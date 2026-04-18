/*
 * @lc app=leetcode id=326 lang=cpp
 *
 * [326] Power of Three
 */

// @lc code=start
#include <iostream>
#include <cmath>
using namespace std;
class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        // if (n == 1)
        // {
        //     return true;
        // }
        // else if (n <= 0 || n % 3 != 0)
        // {
        //     return false;
        // }
        // return isPowerOfThree(n / 3);

        // constant time solution
        const int highestPossibleValus = pow(3, 19);
        return n > 0 && highestPossibleValus % n == 0;
    }
};
// @lc code=end
