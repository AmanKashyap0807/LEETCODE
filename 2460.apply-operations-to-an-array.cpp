/*
 * @lc app=leetcode id=2460 lang=cpp
 *
 * [2460] Apply Operations to an Array
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
class Solution
{
public:
    vector<int> applyOperations(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                nums[i] = nums[i] * 2;
                nums[i + 1] = 0;
            }
        }
        int j = 0; // position for next non-zero
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                swap(nums[i], nums[j]);
                j++;
            }
        }
        return nums;
    }
};
// @lc code=end
