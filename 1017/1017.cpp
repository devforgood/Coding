#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <memory.h>

#define MAX 1001*2

using namespace std;

vector<int> vtx[MAX]; 
int slt[MAX];
bool done[MAX]; 
int n; 
bool PrimeArray[MAX];
vector<int> a, b, answer;
int bias = 50;
int fix_a;
int fix_b;

void Eratos(int n)
{
	PrimeArray[0] = false;
	PrimeArray[1] = false;

	for (int i = 2; i < n + 1; ++i)
		PrimeArray[i] = true;


	for (int i = 2; i * i <= n; ++i)
	{
		if (PrimeArray[i])
		{
			for (int j = i * i; j <= n; j += i)
				PrimeArray[j] = false;
		}
	}
}

bool dfs(int x) 
{
	for (int i = 0; i < vtx[x].size(); i++) 
	{
		int p = vtx[x][i];

		if (done[p]) 
			continue;

		if (p == fix_a || p == fix_b)
			continue;

		done[p] = true;

		if (PrimeArray[a[x] + b[p - bias]] == false)
			continue;

		if (slt[p] == -1 || dfs(slt[p])) {
			slt[p] = x;
			return true;
		}

	}
	return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	Eratos(MAX-1);

	cin >> n;
	int v;
	int even = false;
	for (int i = 0; i < n; ++i)
	{
		cin >> v;
		if (i == 0 && (v & 1) == 0)
			even = true;

		if (v & 1)
			a.push_back(v);
		else
			b.push_back(v);
	}

	if (a.size() != b.size())
	{
		cout << -1;
		return 0;
	}

	if (even)
		swap(a, b);

	for (int i = 0; i < a.size(); ++i)
	{
		for (int j = 0; j < b.size(); ++j)
		{
			if (PrimeArray[a[i] + b[j]])
				vtx[i].push_back(j + bias);
		}
	}

	for (int i = 0; i < b.size(); ++i)
	{
		memset(slt, -1, sizeof(slt));
		if (PrimeArray[a[0] + b[i]]==false)
			continue;
		int match = 1;

		slt[i + bias] = 0;
		fix_a = 0;
		fix_b = i + bias;
		for (int j = 1; j < a.size(); ++j)
		{
			memset(done, false, sizeof(done));
			done[0] = done[i + bias] = 1;
			match += dfs(j);
		}
		if (match != b.size())
			continue;

		answer.push_back(b[i]);
	}

	if (answer.size())
	{
		sort(answer.begin(), answer.end());
		for (auto v : answer)
			cout << v << " ";
	}
	else
		cout << -1;

}
