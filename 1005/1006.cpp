#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>


using namespace std;

struct node
{
    int x;
    int y;
    int cnt;
};

int n, w;
int arr[2][10001];
bool visited[2][10001];

int direction[4][2] = {
    {-1, 0},
    {0, -1},
    {1, 0},
    {0, 1}
};

int bfs(int x, int y)
{
    queue<node> q;
    q.push({ x, y, 1 });

    while (q.empty() == false)
    {
        node cur = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = cur.x + direction[i][0];
            int ny = cur.y + direction[i][0];

            if (nx < 0 || nx >= 2 )
                continue;

			if (ny < 0)
				ny = n - 1;

			if (ny >= n)
				ny = 0;

            int cnt = cur.cnt;
            if (arr[cur.x][cur.y] + arr[nx][ny] <= w)
                cnt += 1;

            q.push({ nx, ny, cnt });


        }

    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> w;


    }


}
