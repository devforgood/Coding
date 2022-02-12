
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


    TEST_CLASS(FunctionDevelopment)
    {
    public:

        vector<int> solution(vector<int> progresses, vector<int> speeds) {
            vector<int> answer;

            queue<pair<int, int>> q;
            for (int i = 0; i < progresses.size(); ++i)
                q.push({ progresses[i], speeds[i] });

            while (q.empty() == false)
            {
                int diff = 100 - q.front().first;
                int days = diff / q.front().second;
                days += (diff % q.front().second != 0) ? 1 : 0;

                int cnt = 0;
                while (q.empty()==false && q.front().first + (days * q.front().second) >= 100 )
                {
                    q.pop();
                    ++cnt;
                }
                answer.push_back(cnt);
            }




            return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            vector<int> progresses = { 93, 30, 55 };
            vector<int> speeds = { 1, 30, 5 };

            vector<int> answer = { 2, 1 };

            Assert::AreEqual(true, solution(progresses, speeds) == answer);

        }



    };
}
