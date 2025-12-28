/*
 * @lc app=leetcode id=1685 lang=cpp
 *
 * [1685] Sum of Absolute Differences in a Sorted Array
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> getSumAbsoluteDifferences(vector<int> &nums)
    {
        // brute force method
        // int n = nums.size();
        // vector<int> ans(n, 0);
        // for (int i = 0; i < n; i++)
        // {
        //     int sum = 0;
        //     for (int j = 0; j < n; j++)
        //     {
        //         if (i != j)
        //         {
        //             sum += abs(nums[i] - nums[j]);
        //         }
        //     }
        //     ans[i] = sum;
        // }
        // return ans;

        // prefix sum method
        int n = nums.size();
        vector<int> psa(n, 0);
        psa[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            psa[i] = psa[i - 1] + nums[i];
        }
        vector<int> ans(n, 0);
        ans[0] = abs(nums[0] * (n - 1) - (psa[n - 1] - psa[0]));
        for (int i = 1; i < n - 1; i++)
        {
            ans[i] = (nums[i] * i - psa[i - 1]) + ((psa[n - 1] - psa[i]) - nums[i] * (n - 1 - i));
        }
        ans[n - 1] = abs(nums[n - 1] * (n - 1) - psa[n - 2]);
        return ans;
    }
};
// @lc code=end
