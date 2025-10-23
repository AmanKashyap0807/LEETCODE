/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 */

// @lc code=start
#include <string>
#include <cctype>
using namespace std;
class Solution
{
private:
    // Helper function to check if a substring is a palindrome
    bool isPalindrome(const string &s, int l, int r)
    {
        while (l < r)
        {
            if (s[l] != s[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

public:
    bool validPalindrome(string s)
    {
        if (s.empty())
            return true;

        int l = 0;
        int r = s.size() - 1;
        while (l < r)
        {
            if (s[l] != s[r])
            {
                // Found a mismatch.
                // We must use our one deletion.
                // Check if either skipping s[l] OR skipping s[r] makes a palindrome.
                return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
            }
            // Characters match, continue inwards.
            l++;
            r--;
        }
        // If the loop completes, the string was already a palindrome.
        return true;
    }
};
// @lc code=end
