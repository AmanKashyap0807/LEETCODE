/*
 * @lc app=leetcode id=1614 lang=cpp
 *
 * [1614] Maximum Nesting Depth of the Parentheses
 */

// @lc code=start
#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    int maxDepth(string s)
    {
        int count = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                count++;
                ans = max(count, ans);
            }
            else if (s[i] == ')')
            {
                count--;
            }
                }
        return ans;
    }
};
// @lc code=end
