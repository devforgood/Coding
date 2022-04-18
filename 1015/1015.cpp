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

    //vector<pair<int, int>> arr;

    //int n;
    //cin >> n;
    //for (int i = 0; i < n; ++i)
    //{
    //    int num;
    //    cin >> num;
    //    arr.push_back({ num, i });
    //}

    //sort(arr.begin(), arr.end());

    //vector<pair<int, int>> answer;
    //for (int i = 0; i < n; ++i)
    //{
    //    answer.push_back({ arr[i].second, i });
    //}

    //sort(answer.begin(), answer.end());

    //for (auto v : answer)
    //    cout << v.second << " ";


    // short code
    int n, a[50] = { 0, }, b[50] = { 0, };
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        for(int j=0;j<i;++j)
            a[j] > a[i] ? b[j]++ : b[i]++;
    }

    for (int i = 0; i < n; ++i)
        cout << b[i] << ' ';
   
}
