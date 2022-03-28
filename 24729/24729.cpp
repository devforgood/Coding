#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>

using namespace std;





int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);



    int n;
    int answer = -1;
    map<int, int> stairs;

    cin >> n;


    int a;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        stairs[a] += 1;
    }


    bool incre = true;
    int start = stairs.begin()->first;
    int end = stairs.rbegin()->first;

    for (int i = start + 1; i <= end - 1; ++i)
    {
        if (stairs[i] < 2)
        {
            cout << "-1";
            return 0;
        }
    }


    int index = stairs.begin()->first;
    int last_index = 0;
    int i = 1;
    for (; i < n; ++i)
    {
        if (incre)
        {
            if (stairs[index + 1] == 0)
                incre = false;
        }
        else
        {
            if (stairs[index - 1] == 0)
                incre = true;
        }

        if (stairs[index] <= 0)
            break;

        stairs[index] -= 1;

        last_index = index;
        if (incre)
            ++index;
        else
            --index;
    }

    if (start != end && i==n && abs(index - start) == 1)
        answer = 1;

    cout << answer;
}
