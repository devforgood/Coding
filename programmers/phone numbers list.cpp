
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


    TEST_CLASS(PhoneNumbersList)
    {
    public:

        bool solution(vector<string> phone_book) {
            bool answer = true;

            sort(phone_book.begin(), phone_book.end());
            for (int i = 1; i < phone_book.size(); ++i)
            {
                int size = phone_book[i - 1].size();
                if (phone_book[i].substr(0, size) == phone_book[i - 1])
                    return false;
            }

            return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            vector<string> phone_book = { "119", "97674223", "1195524421" };
            Assert::AreEqual(false, solution(phone_book));

        }

        TEST_METHOD(TestMethod2)
        {
            vector<string> phone_book = { "123","456","789" };
            Assert::AreEqual(true, solution(phone_book));

        }

        TEST_METHOD(TestMethod3)
        {
            vector<string> phone_book = { "12","123","1235","567","88" };
            Assert::AreEqual(false, solution(phone_book));

        }


    };
}
