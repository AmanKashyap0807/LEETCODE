/*
 * @lc app=leetcode id=983 lang=cpp
 *
 * [983] Minimum Cost For Tickets
 */

// @lc code=start
#include <iostream>
#include <vector>
class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int n = days.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--)
        {

            // 1 day pass
            // int j = i;
            // while (j < n &&
            //        days[j] < days[i] + 1)
            // {
            //     j++;
            // }

            // int cost1 =
            //     costs[0] + dp[j];

            // 7 day pass
            // j = i;
            // while (j < n &&
            //        days[j] < days[i] + 7)
            // {
            //     j++;
            // }
            // int cost7 =
            //     costs[1] + dp[j];

            // 30 day pass
            // j = i;
            // while (j < n &&
            //        days[j] < days[i] + 30)
            // {
            //     j++;
            // }

            // int cost30 =
            //     costs[2] + dp[j];

            int next1 = lower_bound(days.begin(),
                                    days.end(),
                                    days[i] + 1) -
                        days.begin();

            int next7 = lower_bound(days.begin(),
                                    days.end(),
                                    days[i] + 7) -
                        days.begin();

            int next30 = lower_bound(days.begin(),
                                     days.end(),
                                     days[i] + 30) -
                         days.begin();

            int cost1 =
                costs[0] + dp[next1];

            int cost7 =
                costs[1] + dp[next7];

            int cost30 =
                costs[2] + dp[next30];
            dp[i] =
                min({cost1,
                     cost7,
                     cost30});
        }

        return dp[0];
    }
};
// @lc code=end
