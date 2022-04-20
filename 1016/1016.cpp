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

	long long min, max;
	cin >> min >> max;

    long long answer = max - min + 1;
    vector<bool> arr(answer, false);
    for (long long i = 2; i * i <= max;++i)
    {
        long long quotient = min / (i * i);
        long long remainder = min % (i * i);

        for(long long num = (remainder != 0)?(quotient +1): quotient;num * (i * i) <= max;++num)
        {
            if (arr[num * (i * i) - min] == false)
            {
                arr[num * (i * i) - min] = true;
                answer -= 1;
            }
        }
    }

    cout << answer;
}
