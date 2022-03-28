#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>

using namespace std;


vector<long long> calc(const vector<long long>& v, int N) {
    vector<long long> ans(N);
    ans[0] = 1;

    for (int x = 1; x < N; x++) {
        for (int y = 0; y < x; y++) {
            long long m = 1000000000000000000; // (1e18)
            for (int z = y; z <= x; z++) {
                m = min(m, v[z]);
            }

            ans[x] = ans[x] + ans[y] * m;
            ans[x] = ans[x] % 1000000007; // (1e9 + 7)
        }
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
