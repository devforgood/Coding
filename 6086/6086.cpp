#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <memory.h>

using namespace std;


#define MAX 52

int n;
int capacity[MAX][MAX];
int flow[MAX][MAX];

int NetworkFlow(int source, int sink)
{
    int answer = 0;

    while (true)
    {
        vector<int> arr(MAX, -1);
        queue<int> q;
        arr[source] = source;
        q.push(source);

        // 최단 경로 찾기
        while (q.empty() == false && arr[sink] == -1)
        {
            int cur = q.front();
            q.pop();

            for (int i = 0; i < MAX; ++i)
            {
                if (capacity[cur][i] - flow[cur][i] > 0 && arr[i] == -1)
                {
                    q.push(i);
                    arr[i] = cur;
                }
            }
        }

        // 목적지까지 경로가 없으면 중단
        if (arr[sink] == -1)
            break;

        // 경로중에서 최소 남은 용량
        int c = 9e8;
        for (int i = sink; i != source; i = arr[i])
        {
            c = min(capacity[arr[i]][i] - flow[arr[i]][i], c);
        }
        
        // 경로의 유량 증가, 반대 방향 경로 유량 감소
        for (int i = sink; i != source; i = arr[i])
        {
            flow[arr[i]][i] += c;
            flow[i][arr[i]] -= c;
        }

        answer += c;

    }

    return answer;

}

int getIndex(char c)
{
    if (c > 'Z')
        c = c - 'a' + 26;
    else
        c = c - 'A';

    return c;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    char a, b;
    int c;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b >> c;
        capacity[getIndex(a)][getIndex(b)] += c;
        capacity[getIndex(b)][getIndex(a)] += c;
    }

    cout << NetworkFlow('A' - 'A', 'Z' - 'A') << '\n';

}
