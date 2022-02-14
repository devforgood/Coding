
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



    TEST_CLASS(MoreSpicy)
    {
    public:


        int solution(vector<int> scoville, int K) {
            int answer = 0;

            priority_queue<int, vector<int>, greater<int>> pq;
            for (int i = 0; i < scoville.size(); ++i)
                pq.push(scoville[i]);


            
            for (;answer < 1000000; ++answer)
            {
                int a = pq.top();
                if (a >= K)
                    return answer;

                if (pq.size() <= 1)
                    return -1;

                pq.pop();
                int b = pq.top();
                pq.pop();

                pq.push(a + b * 2);
            }

            return -1;
        }

        TEST_METHOD(TestMethod1)
        {
            vector<int> scoville = { 1, 2, 3, 9, 10, 12 };
            Assert::AreEqual(2, solution(scoville, 7));
        }



    };
}
