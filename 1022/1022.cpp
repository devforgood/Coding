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

int direction[4][2] =
{
	{0, 1},
	{-1, 0},
	{0, -1},
	{1, 0},
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);



	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;


	map<pair<int, int>, long long> answer;
	int incre = 1;
	int incre_cnt = 0;
	int cnt = 0;
	pair<int, int> pos(0, 0);
	int dir = 0;

	int last_value;
	for (long long i = 1; i < 10000000002; ++i)
	{
		if (r1 <= pos.first && r2 >= pos.first && c1 <= pos.second && c2 >= pos.second)
		{
			last_value = i;
			answer[pos] = i;
			if ((r2 - r1 + 1) * (c2 - c1 + 1) == answer.size())
				break;
		}
		if (cnt >= incre)
		{
			dir = ++dir >= 4 ? 0 : dir;
			cnt = 0;
			++incre_cnt;
			if (incre_cnt >= 2)
			{
				incre_cnt = 0;
				++incre;
			}
		}
		++cnt;

		pos.first += direction[dir][0];
		pos.second += direction[dir][1];

	}

	string str = to_string(last_value);

	for (int i = r1; i <= r2; ++i)
	{
		for (int j = c1; j <= c2; ++j)
		{
			cout << setw(str.length()) << answer[{i, j}] << ' ';
		}

		if(i!=r2)
			cout << '\n';
	}


}
