
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


    TEST_CLASS(Joystick)
    {
    public:

        int solution2(string name) {
            int answer = 0;

            string str;
            for (int i = 0; i < name.size(); ++i)
                str += 'A';


            int cursor = 0;
            while (name != str)
            {
                if (name[cursor] != str[cursor])
                {
                    int up = name[cursor] - str[cursor];
                    int down = 26 - (name[cursor] - str[cursor]);
                    if (up > down)
                        answer += down;
                    else
                        answer += up;

                    str[cursor] = name[cursor];
                }
                else
                {
                    int left = 0;
                    int right = 0;
                    
                    int left_cur = cursor;
                    do
                    {
                        --left_cur;
                        if (left_cur < 0)
                            left_cur = name.size() - 1;
                        ++left;
                    } while (name[left_cur] == str[left_cur]);

                    int right_cur = cursor;
                    do
                    {
                        ++right_cur;
                        if (right_cur >= name.size())
                            right_cur = 0;
                        ++right;
                    }
                    while (name[right_cur] == str[right_cur]);

                    if (right <= left)
                    {
                        answer += right;
                        cursor = right_cur;
                    }
                    else
                    {
                        answer += left;
                        cursor = left_cur;
                    }
                }
            }

            return answer;
        }

        int solution(string name) {
            int LUT[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1 };

            int answer = 0;
            for (auto ch : name)
                answer += LUT[ch - 'A'];
            int len = name.length();
            int left_right = len - 1;
            for (int i = 0; i < len; ++i) {
                int next_i = i + 1;
                while (next_i < len && name[next_i] == 'A')
                    next_i++;
                left_right = min(left_right, i + len - next_i + min(i, len - next_i));
            }
            answer += left_right;
            return answer;
        }

        TEST_METHOD(TestMethod1)
        {

            Assert::AreEqual(true, solution("JEROEN") == 56);
            Assert::AreEqual(true, solution("JAN") == 23);

        }



    };
}
