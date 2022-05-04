#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <memory.h>
#include <string>

using namespace std;

int segment[] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 5 };


int GetSegmentCount(int n, int length)
{
	int cnt = 0;
	for (int i = 0; i < length; ++i)
	{
		cnt += segment[n % 10];
		n /= 10;
	}
	return cnt;
}

void solve()
{
	string num;
	cin >> num;

	int length = num.length();
	int n = atoi(num.c_str());
	int cnt = GetSegmentCount(n, length);
	int next_cnt = 0;
	int sec = 0;
	while (next_cnt != cnt)
	{
		++sec;
		next_cnt = GetSegmentCount(++n, length);
	}

	cout << sec;
}

string s;
int dp[16][110][2];
long long v;

/// <summary>
/// 
/// </summary>
/// <param name="pos">자리 위치</param>
/// <param name="left">남은 선분 개수</param>
/// <param name="bigger">원본 값과 비교해서 큰지</param>
/// <returns></returns>
int solve(int pos, int left, bool bigger)
{
	if (left < 0)
		return 10;
	if (pos == s.size())
		return (bigger && !left ? 0 : 10);
	if (dp[pos][left][bigger] != -1)
		return dp[pos][left][bigger];

	dp[pos][left][bigger] = 10;
	// 0~9 단 bigger false 이면 현재 자리 위치 값 부터 시작
	for (int i = (bigger ? 0 : s[pos] - '0'); i <= 9; ++i)
	{
		int next = solve(pos + 1, left - segment[i], bigger || (i > s[pos] - '0'));
		if (next != 10)
		{
			dp[pos][left][bigger] = i;
			break;
		}
	}
	return dp[pos][left][bigger];
}

void backtrace(int pos, int left, bool bigger)
{
	if (pos == s.size())
		return;

	v = v * 10 + dp[pos][left][bigger];
	backtrace(pos + 1, left - segment[dp[pos][left][bigger]], bigger || (dp[pos][left][bigger] > s[pos] - '0'));
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	string num;
	cin >> num;
	
	int sum = 0;
	for (char& c : num)
		sum += segment[c - '0'];

	memset(dp, -1, sizeof(dp));
	s = string(num.size(), '0');
	solve(0, sum, 0);
	v = 0;
	backtrace(0, sum, 0);
	long long answer = v - stoll(num) + (long long)pow(10, s.size());

	memset(dp, -1, sizeof(dp));
	s = num;
	if (solve(0, sum, 0) != 10)
	{
		v = 0;
		backtrace(0, sum, 0);
		answer = v - stoll(num);
	}

	cout << answer;

 }
