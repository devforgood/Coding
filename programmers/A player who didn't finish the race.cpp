
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


    TEST_CLASS(PlayerWhoDidntFinishRace)
    {
    public:

        string solution(vector<string> participant, vector<string> completion) {
            string answer = "";

            unordered_map<string, int> map;
            for (auto v : participant)
                map[v] += 1;

            for (auto v : completion)
            {
                auto itr = map.find(v);
                if (itr->second <= 1)
                    map.erase(itr);
                else
                    itr->second -= 1;
            }

            if(map.size() > 0)
                answer = (*map.begin()).first;

            return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            vector<string> participant = { "mislav", "stanko", "mislav", "ana" };
            vector<string> completion = { "stanko", "ana", "mislav" };

            Assert::AreEqual(string("mislav"), solution(participant, completion));

        }



    };
}
