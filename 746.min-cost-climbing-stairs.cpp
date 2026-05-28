/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        // int n = cost.size();
        // vector<int> dp(n);
        // dp[0] = cost[0];
        // dp[1] = cost[1];
        // for (int i = 2; i < n; i++)
        // {
        //     dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        // }
        // return min(dp[n - 1], dp[n - 2]);
        // above has omega n space complexity
        // as we only need last two value we can use two variable changing each time
        int n = cost.size();
        int prev1 = cost[0];
        int prev2 = cost[1];
        for (int i = 2; i < n; i++)
        {
            int temp = cost[i] + min(prev1, prev2);
            prev1 = prev2;
            prev2 = temp;
        }
        return min(prev1, prev2);
    }
};
// @lc code=end
