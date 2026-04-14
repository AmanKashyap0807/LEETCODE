/*
 * @lc app=leetcode id=821 lang=cpp
 *
 * [821] Shortest Distance to a Character
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
class Solution
{
public:
    vector<int> shortestToChar(string s, char c)
    {
        int n = s.size();
        int rd = -1;
        int ld = -1;
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            rd = -1;
            ld = -1;
            for (int j = i; j < n; j++)
            {
                if (s[j] == c)
                {
                    rd = abs(j - i);
                    break;
                }
            }
            for (int j = i - 1; j >= 0; j--)
            {
                if (s[j] == c)
                {
                    ld = abs(i - j);
                    break;
                }
            }
            if (rd != -1 && ld != -1)
            {
                ans[i] = min(rd, ld);
            }
            else if (rd == -1)
            {
                ans[i] = ld;
            }
            else
            {
                ans[i] = rd;
            }
        }
        return ans;
    }
};
// @lc code=end
