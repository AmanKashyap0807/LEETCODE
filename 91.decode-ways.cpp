/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    // int solve(int i, string &s)
    // {

    //     int n = s.size();

    //     if (i == n)
    //         return 1;

    //     if (s[i] == '0')
    //         return 0;

    //     int ways = solve(i + 1, s);

    //     if (i + 1 < n &&
    //         (s[i] == '1' ||
    //          (s[i] == '2' && s[i + 1] <= '6')))
    //     {
    //         ways += solve(i + 2, s);
    //     }

    //     return ways;
    // }

    // int numDecodings(string s)
    // {
    //     return solve(0, s);
    // }

    // DP solution
    int numDecodings(string s)
    {

        int n = s.size();

        vector<int> dp(n + 1, 0);

        dp[n] = 1;

        for (int i = n - 1; i >= 0; i--)
        {

            if (s[i] == '0')
                continue;

            dp[i] = dp[i + 1];

            if (i + 1 < n &&
                (s[i] == '1' ||
                 (s[i] == '2' && s[i + 1] <= '6')))
            {
                dp[i] += dp[i + 2];
            }
        }

        return dp[0];
    }
};
// @lc code=end
