
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



    TEST_CLASS(BigNumberMake)
    {
    public:


        string solution(string number, int k) {
            string answer = "";

            for (int i = 0; i < number.size(); ++i)
            {
                char max_value = '0' - 1;
                int index = 0;
                for (int j = i; j < i + k + 1; ++j)
                {
                    if (max_value < number[j])
                    {
                        max_value = number[j];
                        index = j;
                    }
                }
                k -= (index-i);
                i = index;

                answer += max_value;
                if (number.size() - (index+1) == k)
                {
                    return answer;
                }
                if (k == 0)
                {
                    for (i += 1; i < number.size(); ++i)
                        answer += number[i];

                    return answer;
                }
            }

            return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            Assert::AreEqual(true, solution("987654321", 5) == "9876");
            Assert::AreEqual(true, solution("1924", 2) == "94");
            Assert::AreEqual(true, solution("1231234", 3) == "3234");
        }



    };
}
