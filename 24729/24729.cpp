#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>

using namespace std;

int n;
int answer = -1;
int stairs[100001] = { 0, };
int visited[100001] = { 0, };


void dfs(int start, int cur, int cnt)
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
    if (stairs[next] > visited[next])
    {
        dfs(start, next, cnt);
        visited[next] -= 1;
    }

	next = cur + 1;
    if (stairs[next] > visited[next])
    {
        dfs(start, next, cnt);
        visited[next] -= 1;
    }



}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;


    int a;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        stairs[a] += 1;
    }


	dfs(a, a, 0);


    cout << answer;

}
