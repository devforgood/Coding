#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <memory.h>
#include <string>
#include <deque>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	deque<int> q;

	int n, m;
	cin >> n >> m;

	int arr[51];
	for (int i = 0; i < n; ++i)
	{
		q.push_back(i + 1);
		arr[i] = i;
	}

	int cnt = 0;
	for (int i = 0; i < m; ++i)
	{
		int v;
		cin >> v;

		auto it = find(q.begin(),q.end(),v);

		auto idx = distance(q.begin(), it);

		if (q.size()/2 >= idx)
		{
			while (true)
			{
				if (q.front() == v)
				{
					q.pop_front();
					break;
				}
				else
				{
					++cnt;
					q.push_back(q.front());
					q.pop_front();
				}
			}
		}
		else
		{
			while (true)
			{
				if (q.front() == v)
				{
					q.pop_front();
					break;
				}
				else
				{
					++cnt;
					q.push_front(q.back());
					q.pop_back();
				}
			}
		}
	}

	cout << cnt;
}
