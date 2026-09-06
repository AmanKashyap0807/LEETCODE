/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int n = s.size();

        if (n != t.size())
            return false;

        vector<int> arrs(26, 0);
        vector<int> arrt(26, 0);

        for (int i = 0; i < n; i++)
        {
            arrs[s[i] - 'a']++;
            arrt[t[i] - 'a']++;
        }

        for (int i = 0; i < n; i++)
        {
            if (arrs[s[i] - 'a'] != arrt[s[i] - 'a'])
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
