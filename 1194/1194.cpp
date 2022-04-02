#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>


using namespace std;

int n, m;
char maze[51][52];
int answer = -1;
bool visited[1 << 6][51][51];

int direction[4][2] = {
    {-1, 0},
    {0, -1},
    {1, 0},
    {0, 1}
};

struct node
{
    int x;
    int y;
    int depth;
    int keys;
};

void bfs(int x, int y)
{
    queue<node> q;
    q.push({x, y, 0, 0});
    visited[0][x][y] = true;


    while (q.empty() == false)
    {
        node cur = q.front();
        q.pop();

        x = cur.x;
        y = cur.y;
        int keys = cur.keys;

        if (maze[x][y] == '1')
        {
			answer = cur.depth;
			return;
        }
    
        for (int i = 0; i < 4; ++i)
        {
            int next_x = x + direction[i][0];
            int next_y = y + direction[i][1];

            if (next_x < 0 || next_x >= n)
                continue;

            if (next_y < 0 || next_y >= m)
                continue;

            if (visited[keys][next_x][next_y])
                continue;

            if (maze[next_x][next_y] == '#')
                continue;

            if (maze[next_x][next_y] == '.' || maze[next_x][next_y] == '1' || maze[next_x][next_y] == '0')
            {
                visited[keys][next_x][next_y] = true;
                q.push({ next_x, next_y, cur.depth + 1, keys });
            }
            else if (maze[next_x][next_y] >= 'A' && maze[next_x][next_y] <= 'F')
            {
                if ((keys & (1 << (maze[next_x][next_y] - 'A'))) != 0)
                {
                    visited[keys][next_x][next_y] = true;
                    q.push({ next_x, next_y, cur.depth + 1, keys });
                }
            }
            else if (maze[next_x][next_y] >= 'a' && maze[next_x][next_y] <= 'f')
			{
				int next_keys = keys | (1 << (maze[next_x][next_y] - 'a'));
				visited[next_keys][next_x][next_y] = true;
				q.push({ next_x, next_y, cur.depth + 1, next_keys });
			}

        }
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    int x, y;
    for (int i = 0; i < n; ++i)
    {
        cin >> maze[i];
        for (int j = 0; j < m; ++j)
        {
            if (maze[i][j] == '0')
            {
                x = i;
                y = j;
            }
        }

    }

    bfs(x, y);

    cout << answer;

}
