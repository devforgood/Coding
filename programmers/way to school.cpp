
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



    TEST_CLASS(WayToSchool)
    {
    public:


        int solution(int m, int n, vector<vector<int>> puddles) {
  
            int arr[102][102] = { 0, };
            for (int i = 0; i < puddles.size(); ++i)
                arr[puddles[i][1]][puddles[i][0]] = -1;

            for (int i = 0; i <= m; ++i)
            {
                arr[0][i] = -1;
                arr[n+1][i] = -1;
            }
            for (int i = 0; i <= n; ++i)
            {
                arr[i][0] = -1;
                arr[i][m+1] = -1;
            }

            arr[1][1] = 1;
            for (int i = 1; i <= n; ++i)
            {
                for (int j = 1; j <= m; ++j)
                {
                    if (arr[i][j] < 0)
                        continue;

                    arr[i][j] += (arr[i - 1][j] > 0 ? arr[i - 1][j] : 0) % 1000000007;
                    arr[i][j] += (arr[i][j - 1] > 0 ? arr[i][j - 1] : 0) % 1000000007;
                }
            }


            return arr[n][m] % 1000000007;
        }


        TEST_METHOD(TestMethod1)
        {
            vector<vector<int>> puddles = { {2, 2} };
            Assert::AreEqual(true, solution(4, 3, puddles) == 4);
        }



    };
}
