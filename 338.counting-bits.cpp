/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> v(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            int temp = i;
            while (temp > 0)
            {
                if (temp & 1)
                {
                    v[i]++;
                }
                temp >>= 1;
            }
        }
        return v;
    }
};
// @lc code=end
