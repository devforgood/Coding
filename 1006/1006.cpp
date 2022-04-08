#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <memory.h>

using namespace std;

struct node
{
    int x;
    int y;
    int cnt;
};

int n, w;
int arr[2][10002];
int dp[10002][3];

void solve()
{
    for (int i = 2; i <= n; ++i)
    {
        int up = arr[0][i - 1] + arr[0][i] <= w ? 1 : 2;
        int down = arr[1][i - 1] + arr[1][i] <= w ? 1 : 2;
        int vertical = arr[0][i] + arr[1][i] <= w ? 1 : 2;

        dp[i][0] = min({ dp[i - 1][0] + vertical, dp[i - 2][0] + up + down, dp[i - 1][1] + up + 1, dp[i - 1][2] + down + 1 });
        dp[i][1] = min(dp[i - 1][2] + down, dp[i - 1][0] + 1);
        dp[i][2] = min(dp[i - 1][1] + up, dp[i - 1][0] + 1);
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        memset(dp, 0, sizeof(dp));
        cin >> n >> w;

        for (int i = 0; i < 2; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                cin >> arr[i][j];
            }
        }

        int tmp_up = arr[0][1];
        int tmp_down = arr[1][1];

        int answer = 9e8;
        dp[1][0] = arr[0][1] + arr[1][1] <= w ? 1 : 2;
        dp[1][1] = 1;
        dp[1][2] = 1;
        solve();
        answer = min(answer, dp[n][0]);

        if (arr[0][1] + arr[0][n] <= w)
        {
            dp[1][0] = 2;
            dp[1][1] = 1;
            dp[1][2] = 1;
            arr[0][1] = 9e8;
            solve();
            answer = min(answer, dp[n][1]);
            arr[0][1] = tmp_up;
        }

        if (arr[1][1] + arr[1][n] <= w)
        {
            dp[1][0] = 2;
            dp[1][1] = 1;
            dp[1][2] = 1;
            arr[1][1] = 9e8;
            solve();
            answer = min(answer, dp[n][2]);
            arr[1][1] = tmp_down;
        }

        if (arr[0][1] + arr[0][n] <= w && arr[1][1] + arr[1][n] <= w)
        {
            dp[1][0] = 2;
            dp[1][1] = 1;
            dp[1][2] = 1;
            arr[0][1] = 9e8;
            arr[1][1] = 9e8;
            solve();
            answer = min(answer, dp[n-1][0]);
            arr[0][1] = tmp_up;
            arr[1][1] = tmp_down;
        }

        if (n == 1)
        {
            answer = arr[0][1] + arr[1][1] <= w ? 1 : 2;
        }

        cout << answer << '\n';
    }


}
