
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


    TEST_CLASS(GymClothes)
    {
    public:


        int solution(int n, vector<int> lost, vector<int> reserve) {
            int reserve_array[31] = { 0, };

            sort(lost.begin(), lost.end());
            sort(reserve.begin(), reserve.end());


            for (int i = 0; i < reserve.size(); ++i)
            {
                auto itr = find(lost.begin(), lost.end(), reserve[i]);
                if (itr != lost.end())
                {
                    lost.erase(itr);
                    continue;
                }

                reserve_array[reserve[i]] += 1;
            }
            int answer = n - lost.size();


            for (int i = 0; i < lost.size(); ++i)
            {
                if (reserve_array[lost[i] - 1] != 0)
                {
                    reserve_array[lost[i] - 1] -= 1;
                    ++answer;
                }
                else if (reserve_array[lost[i] + 1] != 0)
                {
                    reserve_array[lost[i] + 1] -= 1;
                    ++answer;
                }
            }

            return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            vector<int> lost = { 2,4 };
            vector<int> reserve = { 1,3,5 };

            Assert::AreEqual(5, solution(5, lost, reserve));

        }

        TEST_METHOD(TestMethod2)
        {
            vector<int> lost = { 2,3,5 };
            vector<int> reserve = { 1,2,4,6 };

            Assert::AreEqual(6, solution(6, lost, reserve));

        }


    };
}
