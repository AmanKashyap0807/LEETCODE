/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void solve(int ind, vector<int> &nums, vector<vector<int>> &ans)
    {
        if (ind >= nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int i = ind; i < nums.size(); i++)
        {
            swap(nums[ind], nums[i]);
            solve(ind + 1, nums, ans);
            swap(nums[ind], nums[i]);
        }
    }

    // learn below that how the change in passing of parameter drop the space complexity by 80 percante
    // void solve(int ind, vector<int> nums, vector<vector<int>> &ans)
    // {
    //     if (ind >= nums.size())
    //     {
    //         ans.push_back(nums);
    //         return;
    //     }
    //     for (int i = ind; i < nums.size(); i++)
    //     {
    //         swap(nums[ind], nums[i]);
    //         solve(ind + 1, nums, ans);
    //         // swap(nums[ind], nums[i]);
    //     }
    // }

    vector<vector<int>> permute(vector<int> &nums)
    {
        int ind = 0;
        vector<vector<int>> ans;
        solve(ind, nums, ans);
        return ans;
    }
};
// @lc code=end
