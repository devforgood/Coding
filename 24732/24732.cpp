#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>

using namespace std;


vector<long long> calc(const vector<long long>& v, int N) {
    vector<long long> ans(N);
    ans[0] = 1;

    long long sum = 0;
    for (int i = 1; i < N; ++i)
    {
        ans[i] = (sum + ans[i - 1] * min(v[i], v[i - 1])) % 1000000007;
        sum = ans[i];
    }


    return ans;
}




int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n;
    cin >> n;

    vector<long long> v;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    auto answer = calc(v, n);


    for(int i=0;i<answer.size();++i)
        cout << answer[i] << '\n';
}
