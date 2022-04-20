#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <memory.h>


using namespace std;


// initialize to -1
int dp[100];

int solve3(int n)
{
    // base case
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;

    return solve3(n - 1) + solve3(n - 3) + solve3(n - 5);
}

// this function returns the number of
// arrangements to form 'n'
int solve2(int n)
{
    // base case
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;

    // checking if already calculated
    if (dp[n] != -1)
        return dp[n];

    // storing the result and returning
    return dp[n] = solve2(n - 1) + solve2(n - 3) + solve2(n - 5);
}

int solve(int n)
{
    memset(dp, 0, sizeof(dp));

    // base case
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;

    dp[0] = 1;

    for (int i = 1; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + (i - 3 >= 0 ? dp[i - 3] : 0) + (i - 5 >= 0 ? dp[i - 5] : 0);
    }

    return dp[n];
}
int main()
{
    memset(dp, -1, sizeof(dp));

    cout << solve(7);

}
