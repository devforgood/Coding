#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <memory.h>

using namespace std;

pair<double, double> arr[21];
bool visited[21];
int n;
int half;

double calc()
{
    pair<double, double> a, b;
    for (int i = 0; i < n; ++i)
    {
        if (visited[i])
        {
            a.first += arr[i].first;
            a.second += arr[i].second;
        }
        else
        {
            b.first += arr[i].first;
            b.second += arr[i].second;
        }
    }

    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

double dfs(int index, int level)
{
    if (level == half)
        return calc();

    double answer = 9e8;
    for (int i = index; i < n; ++i)
    {
        visited[i] = true;
        answer = min(answer, dfs(i + 1, level + 1));
        visited[i] = false;
    }
    return answer;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(7);
    int t;
    cin >> t;
    while (t--)
    {
        memset(visited, 0, sizeof(visited));
        cin >> n;
        half = n / 2;
        for (int i = 0; i < n; ++i)
            cin >> arr[i].first >> arr[i].second;

        cout << dfs(0, 0) << "\n";
    }


}
