
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


    TEST_CLASS(Network)
    {
    public:

        int arr[1000001];

        int Find(int a)
        {
            if (arr[a] == a)
                return a;
            else
                return arr[a] = Find(arr[a]); // arr[a] 값 세팅 생략시 시간 초과된다.
        }

        void Union(int a, int b)
        {
            int pa = Find(a);
            int pb = Find(b);

            if (pa > pb)
                arr[pa] = pb;
            else if (pa < pb)
                arr[pb] = pa;

        }

        int solution(int n, vector<vector<int>> computers) {
            int answer = 0;


            for (int i = 0; i <= n; ++i)
                arr[i] = i;

            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (computers[i][j] == 1 && computers[j][i]==1)
                    {
                        Union(i+1, j+1);
                    }
                }
            }

            for (int i = 1; i <= n; ++i)
            {
                if (Find(i) == i)
                    ++answer;
            }
            


            return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            vector<vector<int>> computers = { {1, 1, 0},{1, 1, 0},{0, 0, 1} };
            Assert::AreEqual(true, solution(3, computers) == 2);
        }



    };
}
