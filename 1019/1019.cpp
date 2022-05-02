#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <memory.h>
#include <string>

using namespace std;

void solve2(int n)
{
	int answer[10] = { 0, };
	for (int i = 1; i <= n; ++i)
	{
		string str = to_string(i);
		for (int j = 0; j < str.length(); ++j)
		{
			answer[str[j] - '0']++;
		}
	}

	for (int i = 0; i < 10; ++i)
		cout << answer[i] << ' ';
}

void solve3(int n)
{
	int answer[10] = { 0, };
	string num = to_string(n);

	for (int i = 0; i < 10; ++i)
	{
		if (n >= 10)
		{
			answer[i]++;
		}
		else
		{
			if (num[num.length()-1] - '0' >= i)
				answer[i]++;
		}
	}


	int len = 1;
	for (int i = num.length()-2; i >= 0; --i)
	{
		int cur_num = num[i] - '0';
		int prev_num = num[i + 1] - '0';

		for (int j = 1; j < 10; ++j)
		{

			if (cur_num >= j)
			{
				answer[j] *= prev_num+1;

				answer[j] += (cur_num+1) * len;
			}
			else if (prev_num >= j)
			{
				answer[j] += 1;
			}
		}

		len *= 10;
	}

	for (int i = 0; i < 10; ++i)
		cout << answer[i] << ' ';
}

void calc(int x, int answer[], int point)
{
	while (x > 0)
	{
		answer[x % 10] += point;
		x /= 10;
	}
}

void solve(int n)
{
	int answer[10] = { 0, };

	int start = 1;
	int point = 1;
	while (start <= n)
	{
		// 끝자리 9로 만들기
		while (n % 10 != 9 && start <= n)
		{
			calc(n, answer, point);
			--n;
		}

		if (n < start)
			break;

		// 끝자리 0으로 만들기
		while (start % 10 != 0 && start <= n)
		{
			calc(start, answer, point);
			start++;
		}

		start /= 10;
		n /= 10;

		for (int i = 0; i < 10; ++i)
			answer[i] += (n - start + 1) * point;

		point *= 10;
	}

	for (int i = 0; i < 10; ++i)
		cout << answer[i] << ' ';
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	solve(n);
}
