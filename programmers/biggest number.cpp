
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


        string solution(vector<int> numbers) {
            string answer = "";

            vector<string> num;
            for (int i = 0; i < numbers.size(); ++i)
                num.push_back(to_string(numbers[i]));

            sort(num.begin(), num.end(),[](const string& a, const string& b)->bool
                {
                    return a + b > b + a;
                });

            for (int i = 0; i < num.size(); ++i)
                answer += num[i];

            if (answer[0] == '0')
                return "0";

            return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            vector<int> numbers = { 6, 10, 2 };
            Assert::AreEqual(true, solution(numbers) == "6210");

        }



    };
}
