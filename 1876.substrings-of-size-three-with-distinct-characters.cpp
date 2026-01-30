/*
 * @lc app=leetcode id=1876 lang=cpp
 *
 * [1876] Substrings of Size Three with Distinct Characters
 */

// @lc code=start
#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    int countGoodSubstrings(string s)
    {
        int n = s.size();
        if (n < 3)
        {
            return 0;
        }
        int st = 0;
        int l = 2;
        int count = 0;
        while (l < n)
        {
            if (s[st] == s[st + 1] || s[l] == s[st + 1] || s[l] == s[st])
            {
                st++;
                l++;
                continue;
            }
            count++;
            st++;
            l++;
        }
        return count;
    }
};
// @lc code=end
