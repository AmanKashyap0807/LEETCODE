/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void solve(int ind, vector<int> &nums, vector<int> &subarr, vector<vector<int>> &ans)
    {
        if (ind >= nums.size())
        {
            ans.push_back(subarr);
            return;
        }
        subarr.push_back(nums[ind]);
        solve(ind + 1, nums, subarr, ans);
        subarr.pop_back();
        solve(ind + 1, nums, subarr, ans);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> subarr;
        int ind = 0;
        solve(ind, nums, subarr, ans);
        return ans;
    }
};
// @lc code=end
