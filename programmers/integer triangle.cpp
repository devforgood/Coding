
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


    TEST_CLASS(IntergerTriangle)
    {
    public:

        int solution(vector<vector<int>> triangle) {
            int answer = 0;

            for (int i = triangle.size() - 2; i >= 0; --i)
            {
                for (int j = 0; j < triangle[i].size(); ++j)
                {
                    triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1]);
                }
            }

            answer = triangle[0][0];

            return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            vector<vector<int>> triangle = { {7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5} };
            Assert::AreEqual(true, solution(triangle) == 30);
        }



    };
}
