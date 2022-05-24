#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <memory.h>

using namespace std;

int n;
// 외판원 순회에서는 도시간의 이동이 자유로웠지만 
// 그림 거래에서는 되파는 가격이 구매했던 그림의 가격보다 같거나 커야 한다는 조건이 있다.
// 따라서 메모이제이션을 적용하는 배열은 다음과 같이 3차원 배열을 사용해야 한다.


int dp[16][1<<16][10];
int arr[16][16];

int dfs(int x, int visited, int price)
{
	// 검색 종료 조건
	//if (visited == (1 << n) - 1)
	//{
	//	// 현재 노드에서 시작 노드로 돌아가기 위한 비용
	//	if (arr[x][0] == 0)
	//		return 1e9; // 돌아가는길이 없다면 해당 길은 제외되도록한다.
	//	else
	//		return arr[x][0];
	//}

	// 이전에 방문했던 경로면 과거 데이터를 리턴
	if (dp[x][visited][price] != -1)
		return dp[x][visited][price];

	// 가장 적은 값을 찾기위해 최대값으로 초기화
	dp[x][visited][price] = 0;
	for (int i = 1; i < n; i++)
	{
		// 이전 방문 경로 스킵
		if ((visited & (1 << i)) == (1 << i))
			continue;

		// 갈수 있는 경로인지 확인
		if (arr[x][i] < price)
			continue;

		// 최단 경로로 재귀호출
		dp[x][visited][price] = max(dp[x][visited][price], dfs(i, visited | (1 << i), arr[x][i]) + 1);
	}
	return dp[x][visited][price];
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);




    cin >> n;
    char tmp[751];
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        for (int j = 0; j < n; ++j)
        {
            arr[i][j] = tmp[j] - '0';
        }
    }
	memset(dp, -1, sizeof(dp));

	//int answer = 0;
	//for(int i=1;i<=n;++i)
	//	answer = max(answer, dfs(0, 1, arr[i][i]));

	cout << dfs(0, 1, 0)+1;
}
