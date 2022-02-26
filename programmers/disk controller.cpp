
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


    TEST_CLASS(DiskController)
    {
    public:

        int solution(vector<vector<int>> jobs) {
            int answer = 0;

            sort(jobs.begin(), jobs.end());

            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

            int sum = 0;
            int time = 0;
            int j = 0;
            while (j< jobs.size() || pq.empty() == false)
            {
                if (jobs.size() > j && time >= jobs[j][0])
                {
                    pq.push({ jobs[j][1], jobs[j][0] });
                    ++j;
                    continue;
                }

                if (pq.empty() == false)
                {
                    time += pq.top().first;
                    sum += time - pq.top().second;
                    pq.pop();
                }
                else
                {
                    time = jobs[j][0];
                }
            }

            answer = sum / jobs.size();

            return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            vector<vector<int>> jobs = {{0, 3}, {1, 9}, {2, 6}};
            Assert::AreEqual(9, solution(jobs));
        }
    };
}
