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

    int answer = 0;
    int n;
    int a[50] = { 0, };
    int b[50] = { 0, };
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + n, greater<int>());

    for (int i = 0; i < n; ++i)
    {
        answer += a[i] * b[i];
    }

    cout << answer;
}
