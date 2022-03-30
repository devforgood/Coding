#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <set>

using namespace std;


vector<long long> calc(const vector<long long>& v, int N) {
    vector<long long> ans(N);
    ans[0] = 1;

    vector<set<int>> min_values(N);
    min_values[0].insert(v[0]);

    for (int i = 1; i < N; ++i)
    {
        for(int j=0;j<=i;++j)
            min_values[j].insert(v[i]);

        for (int j = 0; j < i; ++j)
            ans[i] += ans[j] * (*min_values[j].begin());
    }


    return ans;
}


vector<long long> calc5(const vector<long long>& v, int N) {
    vector<long long> ans(N);
    ans[0] = 1;

    vector<long long> min_values(N);
    for (int i = 0; i < N; ++i)
    {
        min_values[i] = v[i]; 
    }
    
    for (int i = 1; i < N; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            min_values[j] = min(min_values[j], v[i]);

            ans[i] += ans[j] * min_values[j];
        }

    }


    return ans;
}

vector<long long> calc1(const vector<long long>& v, int N) {
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

vector<long long> calc3(const vector<long long>& v, int N) {
    vector<long long> ans(N);
    ans[0] = 1;

    map<pair<int, int>, long long> dp;
    for (int i = 0; i < N; ++i)
        dp[{i, i}] = v[i];

    for (int x = 1; x < N; x++) {
        for (int y = 0; y < x; y++) {

            dp[{x, y}] = min(dp[{x - 1, y}], v[x]);

            ans[x] = ans[x] + ans[y] * dp[{x, y}];
            ans[x] = ans[x] % 1000000007; // (1e9 + 7)
        }
    }

    return ans;
}

vector<long long> calc2(const vector<long long>& v, int N) {
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
