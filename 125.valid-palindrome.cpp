/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
#include <string>
#include <cctype>
using namespace std;
class Solution
{
public:
    bool isPalindrome(string s)
    {
        if (s.empty())
            return true;

        int l = 0;
        int r = s.size() - 1;
        while (l < r)
        {
            if (isalnum(s[l]) && isalnum(s[r]))
            {
                if (tolower(s[l]) != tolower(s[r]))
                {
                    return false;
                }
                l++;
                r--;
            }
            else if (!isalnum(s[l]))
            {
                l++;
            }
            else if (!isalnum(s[r]))
            {
                r--;
            }
            else
            {
                l++;
                r--;
            }
        }
        return true;
    }
};
// @lc code=end
