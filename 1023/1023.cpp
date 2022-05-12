#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <memory.h>
#include <string>
#include <deque>
#include <iomanip>

using namespace std;


int n;
long long m;
long long dp[51][2 * 51][2];

/// <summary>
/// 
/// </summary>
/// <param name="a">문자열 위치</param>
/// <param name="b">열린 괄호 수</param>
/// <param name="c">괄호 문자열 여부</param>
/// <returns></returns>
long long dfs(int a, int b, int c)
{
    if (a == n) 
        return c || b;

    if (dp[a][b + 51][c] != -1)
        return dp[a][b + 51][c];

    return dp[a][b + 51][c] = dfs(a + 1, b + 1, c) + dfs(a + 1, b - 1, c || b < 1);
}

void dfs2(int a, int b, int c, long long k) 
{
    if (a == n) 
        return;

    if (dfs(a + 1, b + 1, c) <= k) 
    {
        cout << ')';
        dfs2(a + 1, b - 1, c || b < 1, k - dfs(a + 1, b + 1, c));
    }
    else 
    {
        cout << '(';
        dfs2(a + 1, b + 1, c, k);
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    if (dfs(0, 0, 0) <= m) 
        cout << -1;
    else dfs2(0, 0, 0, m);

}
