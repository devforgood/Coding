#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>

using namespace std;

int n;
int answer = -1;
map<int, int> stairs;


void dfs(int start, int cur, map<int, int> visited, int cnt)
{
    visited[cur] += 1;
    ++cnt;
    if (n == cnt)
    {
        if (abs(start - cur) == 1)
        {
            answer = 1;
        }

        return;
    }

    int next;

	next = cur - 1;
	if (stairs.find(next) != stairs.end())
		if (stairs[next] > visited[next])
			dfs(start, next, visited, cnt);

	next = cur + 1;
	if (stairs.find(next) != stairs.end())
		if (stairs[next] > visited[next])
			dfs(start, next, visited, cnt);


}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;


    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        stairs[a] += 1;
    }

    map<int, int> visited;
    for (auto v : stairs)
    {
        dfs(v.first, v.first, visited, 0);
    }


    cout << answer;

}
