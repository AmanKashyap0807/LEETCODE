/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
#include <iostream>
#include <vector>
class Solution
{
public:
    int fib(int n)
    {
        // if (n == 1)
        //     return 1;
        // else if (n == 0)
        //     return 0;

        // return fib(n - 1) + fib(n - 2);

        // DP memoization method
        if (n == 1)
            return 1;
        else if (n == 0)
            return 0;
        vector<int> fSeries(n + 1);
        fSeries[0] = 0;
        fSeries[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            fSeries[i] = fSeries[i - 1] + fSeries[i - 2];
        }
        return fSeries[n];
    }
};
// @lc code=end
