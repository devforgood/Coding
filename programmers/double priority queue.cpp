
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


    TEST_CLASS(DoublePriorityQueue)
    {
    public:

        vector<int> solution(vector<string> operations) {
            vector<int> answer;

            priority_queue<int> max_pq;
            priority_queue<int, vector<int>, greater<int>> min_pq;


            int size = 0;
            for (int i = 0; i < operations.size(); ++i)
            {
                if (operations[i][0] == 'I')
                {
                    int num = atoi(&operations[i].c_str()[2]);
                    max_pq.push(num);
                    min_pq.push(num);
                    ++size;
				}
				else if (operations[i] == "D 1" && size != 0)
				{
                    max_pq.pop();

                    --size;
				}
				else if (operations[i] == "D -1" && size != 0)
				{
                    min_pq.pop();
                    --size;
				}

                if (size == 0)
                {
                    max_pq = priority_queue<int>();
                    min_pq = priority_queue<int, vector<int>, greater<int>>();
                }
            }

            if (size == 0)
            {
                answer = { 0, 0 };
            }
            else
            {
                answer.push_back(max_pq.top());
                answer.push_back(min_pq.top());
            }

            return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            vector<string> operations = { "I 16","D 1" };
            vector<int> answer = { 0, 0 };
            Assert::AreEqual(true, solution(operations) == answer);
        }

        TEST_METHOD(TestMethod2)
        {
            vector<string> operations = { "I 7","I 5","I -5","D -1" };
            vector<int> answer = { 7, 5 };
            Assert::AreEqual(true, solution(operations) == answer);
        }

        TEST_METHOD(TestMethod3)
        {
            vector<string> operations = { "I 4", "I 3", "I 2", "I 1", "D 1", "D 1", "D -1", "D -1", "I 5", "I 6" };
            vector<int> answer = { 6, 5 };
            Assert::AreEqual(true, solution(operations) == answer);
        }

    };
}
