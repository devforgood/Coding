#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <memory.h>
#include <regex>

using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    regex re("(100+1+|01)+");

    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        if (regex_match(str, re))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }


}
