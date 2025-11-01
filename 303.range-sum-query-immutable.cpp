/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */

// @lc code=start
#include <vector>
using namespace std;
class NumArray
{
private:
    vector<int> prefixSum;

public:
    NumArray(vector<int> &nums)
    {
        if (nums.empty())
            return;
        // implement prefix sum array
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
            {
                prefixSum.push_back(nums[i]);
            }
            else
            {
                prefixSum.push_back(prefixSum[i - 1] + nums[i]);
            }
        }
    }

    int sumRange(int left, int right)
    {
        if (left == 0)
        {
            return prefixSum[right];
        }
        else
        {
            return prefixSum[right] - prefixSum[left - 1];
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end
