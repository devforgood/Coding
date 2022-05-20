#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <memory.h>

using namespace std;

int dp[751*2][751*2][4];
int arr[751*2][751*2];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);



    int r, c;

    cin >> r >> c;
    char tmp[751];
    for (int i = 1; i <= r; ++i)
    {
        cin >> tmp;
        for (int j = 1; j <= c; ++j)
        {
            arr[i][j] = tmp[j-1] - '0';

            if (arr[i][j])
            {
                dp[i][j][2] = dp[i - 1][j - 1][2] + 1;
                dp[i][j][3] = dp[i - 1][j + 1][3] + 1;
            }
        }
    }

    for (int i = r; i > 0; --i)
    {
        for (int j = 1; j <= c; ++j)
        {
            if (arr[i][j] == 0)
                continue;

            dp[i][j][0] = dp[i + 1][j - 1][0] + 1;
            dp[i][j][1] = dp[i + 1][j + 1][1] + 1;
        }
    }


    int answer = 0;
    for (int i = 0; i <= r; ++i)
    {
        for (int j = 0; j <= c; ++j)
        {
            for (int k = 1; k<= min(dp[i][j][0], dp[i][j][1]); ++k)
            {
                if (arr[i+2*(k-1)][j] && dp[i+2*(k-1)][j][2]>=k && dp[i+2*(k-1)][j][3]>=k)
                {
                    answer = max(answer, k);
                }
            }
        }
    }

    cout << answer;


}
