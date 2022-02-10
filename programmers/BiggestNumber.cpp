
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


    TEST_CLASS(BiggestNumber)
    {
    public:

        struct cmp {
            bool operator()(string a, string b)
            {
                // 최소 길이 비교후 같을 경우 두개의 최대 길이로 비교
                return a + b > b + a;
            }
        };

        string solution(vector<int> numbers) {
            string answer = "";
            vector<string> num;
            for (int i = 0; i < numbers.size(); ++i)
                num.push_back(to_string(numbers[i]));

            sort(num.begin(), num.end(), cmp());

            for (int i = 0; i < num.size(); ++i)
                answer += num[i];

            if (answer[0] == '0')
                return "0";

            return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            vector<int> numbers = { 3, 30, 34, 5, 9 };

            Assert::AreEqual(string("9534330"), solution(numbers));

        }



    };
}
