/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 2, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            int robCurrent = nums[i] + dp[i + 2];
            int skipCurrent = dp[i + 1];
            dp[i] = max(robCurrent, skipCurrent);
        }
        return dp[0];
    }
};
// @lc code=end
