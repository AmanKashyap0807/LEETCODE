/*
 * @lc app=leetcode id=1922 lang=cpp
 *
 * [1922] Count Good Numbers
 */

// @lc code=start
class Solution
{
public:
    long long MOD = 1e9 + 7;

    long long power(long long base, long long exp)
    {
        long long result = 1;

        while (exp > 0)
        {
            if (exp % 2 == 1)
            {
                result = (result * base) % MOD;
            }

            base = (base * base) % MOD;

            exp = exp / 2;
        }

        return result;
    }

    int countGoodNumbers(long long n)
    {
        long long evenCount = (n + 1) / 2;
        long long oddCount = n / 2;

        long long evenPart = power(5, evenCount);
        long long oddPart = power(4, oddCount);

        return (evenPart * oddPart) % MOD;
    }
};
// @lc code=end
