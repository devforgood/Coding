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

    int n;
    cin >> n;

    double arr[50];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int count[50] = { 0, };
    for (int i = 0; i < n; ++i)
    {
        double max_slope = -1000000000;
        for (int j = i + 1; j < n; ++j)
        {
            double slope = (arr[j] - arr[i]) / (j - i);
            if (slope > max_slope)
            {
                max_slope = slope;
                ++count[i];
                ++count[j];
            }
        }
    }



    cout << *max_element(count, count+n);

}
