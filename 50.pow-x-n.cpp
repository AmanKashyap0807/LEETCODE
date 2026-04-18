/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
#include <iostream>
class Solution
{
public:
    double myPow(double x, int N)
    {
        long long n = N;

        if (n < 0)
        {
            x = 1 / x;
            n = -n;
        }

        if (n == 0)
            return 1;

        double half = myPow(x, n / 2);

        if (n % 2 == 0)
            return half * half;
        else
            return half * half * x;
    }
};
// @lc code=end
