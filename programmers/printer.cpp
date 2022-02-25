
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


    TEST_CLASS(Printer)
    {
    public:

        int solution(vector<int> priorities, int location) {
            int answer = 0;

            queue<pair<int, int>> q;
            for (int i=0;i<priorities.size();++i)
                q.push({ priorities[i], i });

            sort(priorities.begin(), priorities.end(), greater<int>());


            while (true)
            {
                auto cur = q.front();
                q.pop();

                if (cur.first == (*priorities.begin()))
                {
                    ++answer;

                    if (cur.second == location)
                        break;

                    priorities.erase(priorities.begin());
                }
                else
                {
                    q.push(cur);
                }
            }


            return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            vector<int> priorities = { 2, 1, 3, 2 };
            Assert::AreEqual(1, solution(priorities, 2));
        }

        TEST_METHOD(TestMethod2)
        {
            vector<int> priorities = { 1, 1, 9, 1, 1, 1 };
            Assert::AreEqual(5, solution(priorities, 0));
        }



    };
}
