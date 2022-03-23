#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;


long long dp[91] = { 0, };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    dp[0] = 0;
    dp[1] = 1;
 
    for (int i = 2; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }


    cout << dp[n];

}