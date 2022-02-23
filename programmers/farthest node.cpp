
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


    TEST_CLASS(FarthestNode)
    {
    public:

        int solution(int n, vector<vector<int>> edge) {
            int answer = 0;

            vector<int> graph[20001];
            bool visited[20001] = { false, };
            int depth[20001] = { 0, };

            for (int i = 0; i < edge.size(); ++i)
            {
                graph[edge[i][0]].push_back(edge[i][1]);
                graph[edge[i][1]].push_back(edge[i][0]);
            }

            queue<int> q;
            q.push(1);
            depth[1] = 1;
            visited[1] = true;
            int max = 1;
            while (q.empty() == false)
            {
                int cur = q.front();
                q.pop();

                for (auto node : graph[cur])
                {
                    if (visited[node])
                        continue;

                    visited[node] = true;

                    q.push(node);

                    depth[node] = depth[cur] + 1;

                    if (max < depth[node])
                        max = depth[node];
                }
            }

            for (int i = 1; i <= n; ++i)
            {
                if (depth[i] == max)
                    ++answer;
            }

            return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            vector<vector<int>> edge = { {3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2} };
            Assert::AreEqual(true, solution(6, edge) == 3);
        }


    };
}
