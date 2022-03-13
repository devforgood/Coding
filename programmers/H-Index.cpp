
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



    TEST_CLASS(HIndex)
    {
    public:


        int solution(vector<int> citations) {
            int answer = 0;

            sort(citations.begin(), citations.end(), greater<int>());

            for (int i = 0; i < citations.size(); ++i)
            {
                if (i + 1 > citations[i])
                {
                    break;
                }
                answer = i + 1;
            }


            return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            vector<int> citations = { 3, 0, 6, 1, 5 };
            Assert::AreEqual(true, solution(citations)==3);
        }

        TEST_METHOD(TestMethod2)
        {
            vector<int> citations = { 25, 8, 5, 3, 3 };
            Assert::AreEqual(true, solution(citations) == 3);
        }


    };
}
