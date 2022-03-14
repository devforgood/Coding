
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



    TEST_CLASS(Carpet)
    {
    public:


        vector<int> solution(int brown, int yellow) {
            vector<int> answer;

            int width = (brown/2+2) - 3;
            int high = 3;

            while(width>=high)
            {
                if(width*high==(brown+yellow))
                    break;

                --width;
                ++high;
            }

            answer = { width, high };

            return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            vector<int> answer = { 4, 3 };
            Assert::AreEqual(true, solution(10, 2) == answer);
        }

        TEST_METHOD(TestMethod2)
        {
            vector<int> answer = { 3, 3 };
            Assert::AreEqual(true, solution(8, 1) == answer);
        }


        TEST_METHOD(TestMethod3)
        {
            vector<int> answer = { 8, 6 };
            Assert::AreEqual(true, solution(24, 24) == answer);
        }

        TEST_METHOD(TestMethod4)
        {
            vector<int> answer = { 5, 3 };
            Assert::AreEqual(true, solution(12, 3) == answer);
        }

    };
}
