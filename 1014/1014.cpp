#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <memory.h>

using namespace std;


char arr[12][12];
int dp[12][1<<10];
int m, n;

bool adjoin(int bit)
{
    for (int i = 0; i < m; ++i)
    {
        // 이진수 11을 시프트 해가며 11이 있는지 확인, 인접한 비트
        int v = (3 << i);
        if ((bit & v) == v)
            return false;
    }
    return true;
}

bool seat(int idx, int bit)
{
    for (int i = 0; i < m; ++i)
    {
        // 비트가 켜진 곳 중 한군데 라도 놓을 수 없는 자리면 실패
        if (arr[idx][i] == 'x' && (bit & (1 << i)))
            return false;
    }
    return true;
}

bool bits(int bit, int prev_bit)
{
    for (int i = 0; i < m; ++i)
    {
        if ((1 << i) & prev_bit)
        {
            // 이전 비트를 기준으로 좌측에 비트가 켜있는지 확인
            if (i > 0 && ((1 << (i - 1)) & bit))
                return false;

            // 이전 비트를 기준으로 우측에 비트가 켜있는지 확인
            if ((1 << (i + 1) & bit))
                return false;
        }
    }
    return true;
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
        memset(arr, 0, sizeof(arr));
        memset(dp, 0, sizeof(dp));

        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            cin >> arr[i];


        vector<pair<int, int>> s;
        for (int i = 0; i < (1 << m); ++i)
        {
            if (adjoin(i))
            {
                int cnt = 0;
                for (int j = 0; j < m; ++j)
                    if ((1 << j) & i)
                        ++cnt;
                s.push_back({ i, cnt });
            }
        }

        int answer = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (auto bit : s)
            {
                if (seat(i, bit.first) == false)
                    continue;

                for (auto prev_bit : s)
                {
                    if (bits(bit.first, prev_bit.first))
                    {
                        dp[i][bit.first] = max(dp[i][bit.first], dp[i - 1][prev_bit.first] + bit.second);
                        answer = max(answer, dp[i][bit.first]);
                    }

                }
            }
        }

        cout << answer << '\n';
    }
}
