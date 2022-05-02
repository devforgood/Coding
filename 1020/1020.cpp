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

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	solve();

 }
