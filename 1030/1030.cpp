#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <memory.h>

using namespace std;

int s, n, k, r1, r2, c1, c2;
void draw(int x, int y, int num)
{
    if ((x / num) % n >= (n-k)/2 && (x / num) % n < (n+k)/2
        && (y / num) % n >= (n - k) / 2 && (y / num) % n < (n+k)/2)
    {
        cout << "1";
    }
    else if (num / n == 0) 
    {
        cout << "0";
    }
    else 
    {
        draw(x, y, num / n);
    }
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int x, y, num;
    cin >> s >> n >> k >> r1 >> r2 >> c1 >> c2;
    num = pow(n, s);

    for (x = r1; x <= r2; ++x) {
        for (y = c1; y <= c2; ++y) {
            draw(x, y, num);
        }
        cout << "\n";
    }
    return 0;

}
