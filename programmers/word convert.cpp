
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



    TEST_CLASS(WordConvert)
    {
    public:


        int solution(string begin, string target, vector<string> words) {
            int answer = 0;

            bool visited[50] = { false, };
            queue<pair<string, int>> q;
            q.push({ begin, 0 });

            while (q.empty() == false)
            {
                auto node = q.front();
                q.pop();

                if (target == node.first)
                    return node.second;

                //if (node.second >= words.size())
                //    continue;

                for (int i = 0; i < words.size(); ++i)
                {
                    if (visited[i] == true)
                        continue;

                    int cnt = 0;
                    for (int j = 0; j < node.first.length(); ++j)
                    {
                        if (node.first[j] != words[i][j])
                            ++cnt;
                    }
                    if (cnt > 1)
                        continue;


                    visited[i] = true;

                    q.push({ words[i], node.second+1 });
                }
            }

            return answer;
        }


        TEST_METHOD(TestMethod1)
        {
            vector<string> words = { "hot", "dot", "dog", "lot", "log", "cog" };
            Assert::AreEqual(true, solution("hit", "cog", words) == 4);
        }

        TEST_METHOD(TestMethod2)
        {
            vector<string> words = { "hot", "dot", "dog", "lot", "log" };
            Assert::AreEqual(true, solution("hit", "cog", words) == 0);
        }


    };
}
