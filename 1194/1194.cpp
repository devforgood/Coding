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

int direction[4][2] = {
    {-1, 0},
    {0, -1},
    {1, 0},
    {0, 1}
};

struct node
{
    int last_x;
    int last_y;
    int x;
    int y;
    int depth;
    int keys;
    int key_count;
    map<pair<int, int>, int> visited;
};

void bfs(int x, int y)
{
    queue<node> q;
    q.push({-1, -1, x, y, 0, 0, 0, map<pair<int, int>, int>() });

    while (q.empty() == false)
    {
        node cur = q.front();
        q.pop();

        x = cur.x;
        y = cur.y;

        if (maze[x][y] == '1')
        {
            if (answer < 0 || answer > cur.depth)
                answer = cur.depth;
            return;
        }
        else if (maze[x][y] >= 'a' && maze[x][y] <= 'z')
        {
            if ((cur.keys & (1 << (maze[x][y] - 'a'))) == 0)
            {
                ++cur.key_count;
                cur.keys |= (1 << (maze[x][y] - 'a'));

                cur.last_x = -1;
                cur.last_y = -1;
            }
        }

        cur.visited[{x, y}] += 1;


        for (int i = 0; i < 4; ++i)
        {
            int next_x = x + direction[i][0];
            int next_y = y + direction[i][1];

            if (cur.last_x == next_x && cur.last_y == next_y)
                continue;

            if (next_x < 0 || next_x >= n)
                continue;

            if (next_y < 0 || next_y >= m)
                continue;

            if (cur.visited[{next_x, next_y}] >= cur.key_count + 1)
                continue;

            if (maze[next_x][next_y] == '#')
                continue;

            if (maze[next_x][next_y] >= 'A' && maze[next_x][next_y] <= 'Z')
            {
                if ((cur.keys & (1 << (maze[next_x][next_y]-'A'))) == 0 )
                    continue;
            }

            q.push({x, y, next_x, next_y, cur.depth + 1, cur.keys, cur.key_count, cur.visited });
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
