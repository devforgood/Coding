
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


    TEST_CLASS(Camouflage)
    {
    public:

        int solution(vector<vector<string>> clothes) {
            int answer = 1;

            map<string, int> cnt;
            for (int i = 0; i < clothes.size(); ++i)
            {
                cnt[clothes[i][1]] += 1;
            }

            for (auto v : cnt)
                answer *= (v.second + 1);


            return answer - 1;
        }

        TEST_METHOD(TestMethod1)
        {
            vector<vector<string>> clothes = { {"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"} };
            Assert::AreEqual(true, solution(clothes) == 5);
        }


    };
}
