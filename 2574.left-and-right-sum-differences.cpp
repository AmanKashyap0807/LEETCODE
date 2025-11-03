/*
 * @lc app=leetcode id=2574 lang=cpp
 *
 * [2574] Left and Right Sum Differences
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> leftRightDifference(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            nums[i] = nums[i] + nums[i - 1];
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                ans.push_back(abs(0 - (nums[n - 1] - nums[i])));
            }
            else
            {
                ans.push_back(abs(nums[i - 1] - (nums[n - 1] - nums[i])));
            }
        }
        return ans;
    }
};
// @lc code=end
