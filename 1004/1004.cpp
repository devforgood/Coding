#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>


using namespace std;


bool detect(int cx, int cy, int r, int x, int y)
{
    int dist = (cx - x) * (cx - x) + (cy - y) * (cy - y);
    if (dist <= r*r)
        return true;
    return false;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int cx, cy, r;
        int x1, y1;
        int x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;

        int cnt = 0;
        int n;
        cin >> n;
        while (n--)
        {
            cin >> cx >> cy >> r;
            if (detect(cx, cy, r, x1, y1) != detect(cx, cy, r, x2, y2))
                ++cnt;
        }

        cout << cnt << '\n';

    }


}
