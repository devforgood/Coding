
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


    TEST_CLASS(TargetNumber)
    {
    public:
        int solution(vector<int> numbers, int target) {
            int answer = 0;

            int cnt = 1 << numbers.size();

            for (int i = 0; i < cnt; ++i)
            {
                int val = 0;
                for (int j = 0; j < numbers.size(); ++j)
                    val += numbers[j] * ((i & (1 << j)) ? -1 : 1);

                if (val == target)
                    ++answer;
            }


            return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            vector<int> numbers = { 1, 1, 1, 1, 1 };
            Assert::AreEqual(5, solution(numbers, 3));
        }

        TEST_METHOD(TestMethod2)
        {
            vector<int> numbers = { 4, 1, 2, 1 };
            Assert::AreEqual(2, solution(numbers, 4));
        }

    };
}
