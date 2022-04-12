#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <memory.h>

using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;

        int val = a % 10;
        for (int i = 1; i < b; ++i)
            val = val * a % 10 ;

        val = val == 0 ? 10 : val;

        cout << val << '\n';
    }

}
