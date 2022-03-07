
#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <stack>

using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace programmers
{


    TEST_CLASS(Rank)
    {
    public:

        bool visited[101];

        int dfs(map<int, vector<int>> & graph, int cur)
        {
            int ret = 1;
            visited[cur] = true;

            for (auto node : graph[cur])
            {
                if (visited[node] == true)
                    continue;

                ret += dfs(graph, node);
            }

            return ret;
        }

        int solution(int n, vector<vector<int>> results) {
            int answer = 0;

            map<int, vector<int>> graph;
            map<int, vector<int>> reverse_graph;

            for (int i = 0; i < results.size(); ++i)
            {
                graph[results[i][0]].push_back(results[i][1]);
                reverse_graph[results[i][1]].push_back(results[i][0]);
            }

            for (int i = 1; i <= n; ++i)
            {
                memset(visited, false, sizeof(visited));
                int cnt = dfs(graph, i);
                memset(visited, false, sizeof(visited));
                int cnt2 = dfs(reverse_graph, i);

                if (cnt + cnt2 - 1 == n)
                    ++answer;
            }

            return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            vector<vector<int>> results = { {4, 3} ,{4, 2},{3, 2},{1, 2},{2, 5} };
            Assert::AreEqual(true, solution(5, results) == 2);
        }


    };
}
