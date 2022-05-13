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

    long long n, l;

    cin >> n >> l;

    int answer = -1;
    int end;
    for (int i = l; i <= 100; i++)
    {
        int val = (i - 1) * i / 2;
        if ((n - val) % i == 0 && (n - val) / i >= 0)
        {
            answer = (n - val) / i;
            end = i;
            break;
        }
    }


    if (answer == -1)
    {
        cout << -1;
    }
    else
    {
        for (int i=0; i < end; ++i)
        {
            cout << i + answer << " ";
        }
    }


}
