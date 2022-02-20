
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


    TEST_CLASS(NExpression)
    {
    public:

        int getNumber(int N, int count)
        {
            string str;
            for (int i = 0; i < count; ++i)
                str += N + '0';

            return atoi(str.c_str());
        }


        int solution(int N, int number) {

            if (N == number) {
                return 1;
            }

            int answer = -1;

            const int MAX = 8;
            set<int> dp[MAX];
            for (int i = 0; i < MAX; ++i)
                dp[i].insert(getNumber(N, i + 1));


            for (int i = 1; i < MAX; ++i)
            {
                for (int j = 0; j < i; ++j)
                {
                    for (auto a : dp[j])
                    {
                        for (auto b : dp[i - j - 1])
                        {
                            dp[i].insert(a + b);
                            dp[i].insert(a - b);
                            dp[i].insert(a * b);
                            if(b != 0) dp[i].insert(a / b);
                        }
                    }
                }

                if (dp[i].find(number) != dp[i].end())
                {
                    answer = i + 1;
                    break;
                }
            }

            return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            Assert::AreEqual(4, solution(5, 12));
            Assert::AreEqual(3, solution(2, 11));
        }


    };
}
