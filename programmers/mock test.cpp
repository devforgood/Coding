
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


    TEST_CLASS(MockTest)
    {
    public:


        vector<int> solution(vector<int> answers) {
            vector<int> answer;

            vector<int> a = { 1, 2, 3, 4, 5 };
            vector<int> b = { 2, 1, 2, 3, 2, 4, 2, 5 };
            vector<int> c = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

            int counts[3] = { 0, };
            for (int i = 0; i < answers.size(); ++i)
            {
                if (a[i % a.size()] == answers[i])
                    ++counts[0];
                if (b[i % b.size()] == answers[i])
                    ++counts[1];
                if (c[i % c.size()] == answers[i])
                    ++counts[2];
            }

            int max_value = max({counts[0], counts[1], counts[2] });

            for (int i = 0; i < 3; ++i)
            {
                if (max_value == counts[i])
                    answer.push_back(i + 1);
            }


            return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            vector<int> answers = { 1,2,3,4,5 };
            vector<int> answer = { 1 };

            Assert::AreEqual(true, solution(answers) == answer);

        }

        TEST_METHOD(TestMethod2)
        {
            vector<int> answers = { 1,3,2,4,2 };
            vector<int> answer = { 1, 2, 3 };

            Assert::AreEqual(true, solution(answers) == answer);

        }


    };
}
