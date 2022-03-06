
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


    TEST_CLASS(SteppingStone)
    {
    public:

        int solution(int distance, vector<int> rocks, int n) {
            int answer = 0;

            sort(rocks.begin(), rocks.end());
            rocks.push_back(distance);

            int min = 0;
            int max = distance;
            int mid;

            while (min <= max)
            {
                mid = (max + min) / 2;

                int last = 0;
                int skip = 0;
                int cur = 0;
                for (int i = 0; i < rocks.size(); ++i)
                {
                    cur = rocks[i] - last;
                    if (mid > cur)
                    {
                        ++skip;
                        if (skip > n)
                            break;
                    }
                    else
                    {
                        last = rocks[i];
                    }
                }
                if (mid > cur)
                {
                    max = mid - 1;
                }
                else
                {
                    if (answer < mid)
                        answer = mid;

                    min = mid + 1;
                }

            }
            return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            vector<int> rocks = { 2, 14, 11, 21, 17 };
            Assert::AreEqual(true, solution(25, rocks, 2) == 4);
        }



    };
}
