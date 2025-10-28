/*
 * @lc app=leetcode id=2697 lang=cpp
 *
 * [2697] Lexicographically Smallest Palindrome
 */

// @lc code=start
#include <string>
using namespace std;
class Solution
{
public:
    string makeSmallestPalindrome(string s)
    {
        int l = 0;
        int r = s.size() - 1;
        while (l < r)
        {
            if (s[l] == s[r])
            {
                l++;
                r--;
            }
            else if (s[l] < s[r])
            {
                s[r] = s[l];
                l++;
                r--;
            }
            else
            {
                s[l] = s[r];
                l++;
                r--;
            }
        }
        return s;
    }
};
// @lc code=end
