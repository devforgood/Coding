
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


    TEST_CLASS(PrimeSearch)
    {
    public:

        bool isPrime(int n) {
            if (n <= 1) {
                return false;
            }

            for (int i = 2; i <= sqrt(n); i++) {
                if ((n % i) == 0) {
                    return false;
                }
            }

            return true;
        }

        void numberCount(string numbers, int* number_count)
        {
            for (int i = 0; i < 10; ++i)
                number_count[i] = 0;

            for (int i = 0; i < numbers.size(); ++i)
                number_count[numbers[i]-'0'] += 1;
        }



        int solution(string numbers) {
            int answer = 0;

            sort(numbers.begin(), numbers.end(), greater<char>());
            int max_number = atoi(numbers.c_str());

            int number_count1[10];
            int number_count2[10];

            numberCount(numbers, number_count1);



            for (int i = 2; i <= max_number; ++i)
            {
                string num = to_string(i);

                numberCount(num, number_count2);

                bool is_continue = false;
                for (int j = 0; j < 10; ++j)
                {
                    if (number_count1[j] < number_count2[j])
                    {
                        is_continue = true;
                        break;
                    }
                }
                if (is_continue)
                    continue;

                if (isPrime(i))
                    ++answer;
            }

            return answer;
        }

        TEST_METHOD(TestMethod1)
        {

            Assert::AreEqual(true, solution("17") == 3);
            Assert::AreEqual(true, solution("011") == 2);

        }



    };
}
