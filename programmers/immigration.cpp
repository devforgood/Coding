
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


    TEST_CLASS(Immigration)
    {
    public:
        long long solution(int n, vector<int> times) {
            long long answer = 0;

            sort(times.begin(), times.end());

            long long min = 1;
            long long max = (long long)(times[times.size() - 1]) * n;
            answer = max;
            long long mid;
            long long cnt;

            while (min <= max)
            {
                mid = (min + max) / 2;
                cnt = 0;
                for (auto t : times)
                    cnt += mid / t;

                if (cnt < n)
                {
                    min = mid + 1;
                }
                else
                {
                    if (answer >= mid)
                        answer = mid;
                    max = mid - 1;
                }
            }


            return answer;
        }
        TEST_METHOD(TestMethod1)
        {
            vector<int> times = { 7, 10 };
            Assert::AreEqual(true, solution(6, times)==28);
        }


    };
}
