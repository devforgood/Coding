
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


    TEST_CLASS(KNumber)
    {
    public:


        vector<int> solution(vector<int> array, vector<vector<int>> commands) {
            vector<int> answer;

            for (int i = 0; i < commands.size(); ++i)
            {
                vector<int> arr(array.begin() + commands[i][0] - 1, array.begin() + commands[i][1]);
                sort(arr.begin(), arr.end());
                answer.push_back(arr.at(commands[i][2] - 1));
            }

            return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            vector<int> array = { 1, 5, 2, 6, 3, 7, 4 };
            vector<vector<int>> commands = { {2, 5, 3}, {4, 4, 1}, {1, 7, 3} };
            vector<int> answer = { 5, 6, 3 };

            Assert::AreEqual(true, solution(array, commands)== answer);

        }



    };
}
