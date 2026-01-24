/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start
#include <cmath>
using namespace std;
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n == 1)
            return true;
        if (n <= 0 || n % 2 != 0)
            return false;

        // Recursive step
        return isPowerOfTwo(n / 2);
    }
};
// @lc code=end
