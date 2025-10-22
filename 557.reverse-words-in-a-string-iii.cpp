/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */

// @lc code=start
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    string reverseWords(string s)
    {
        if (s.empty())
            return s;

        int l = 0;
        int r = 0;
        int i = 0;
        for (; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                r = i;
                reverse(s.begin() + l, s.begin() + r);
                l = i + 1;
            }
        }
        r = i - 1;
        reverse(s.begin() + l, s.begin() + r + 1);
        return s;
    }
};
// @lc code=end
