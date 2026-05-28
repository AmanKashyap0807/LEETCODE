/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i < n + 1; i++)
        {
            int j = 1;
            while (j * j <= i)
            {
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
                j++;
            }
        }
        return dp[n];
    }
};
// @lc code=end
