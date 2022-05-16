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




int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m, n;

    int arr[10][10] = { 0, };
    char num[10];
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> num;
        for (int j = 0; j < m; ++j)
        {
            arr[i][j] = num[j] - '0';
        }
    }

    int answer = -1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            for (int di = -n; di <= n; ++di)
            {
                for (int dj = -m; dj <= m; ++dj)
                {
                    if (di == 0 && dj == 0)
                        continue;


                    int val = 0;
                    for (int an = i, bn = j; an >= 0 && an < n && bn >= 0 && bn < m; an += di, bn += dj)
                    {
                        val += arr[an][bn];
                        if (((int)sqrt(val) * (int)sqrt(val)) == val)
                            answer = max(answer, val);

                        val *= 10;
                    }
                }
            }
        }
    }

    cout << answer;
}
