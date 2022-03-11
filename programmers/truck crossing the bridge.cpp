
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


    TEST_CLASS(TruckCrossingTheBridge)
    {
    public:

        int solution(int bridge_length, int weight, vector<int> truck_weights) {
            int answer = 0;

            int index = 0;
            queue<int> q;
            int cur_weight = 0;
            for (int i = 0; i < bridge_length; ++i)
                q.push(0);

            while (index < truck_weights.size() || cur_weight != 0)
            {
                if (q.empty() == false)
                {
                    cur_weight -= q.front();
                    q.pop();
                }

                if (index < truck_weights.size() 
                    && cur_weight + truck_weights[index] <= weight)
                {
                    q.push(truck_weights[index]);
                    cur_weight += truck_weights[index];
                    ++index;
                }
                else
                {
                    q.push(0);
                }



                ++answer;
            }
            return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            vector<int> truck_weights = { 7, 4, 5, 6 };
            Assert::AreEqual(true, solution(2, 10, truck_weights) == 8);
        }


    };
}
