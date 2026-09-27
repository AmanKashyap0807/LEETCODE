/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void solve(int ind, vector<int> &can, vector<int> &comb, int t, vector<vector<int>> &ans)
    {
        if (t == 0)
        {
            ans.push_back(comb);
            return;
        }
        else if (t < 0 || ind >= can.size())
        {
            return;
        }
        comb.push_back(can[ind]);
        solve(ind, can, comb, t - can[ind], ans);
        comb.pop_back();
        solve(ind + 1, can, comb, t, ans);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        int ind = 0;
        vector<int> comb;
        solve(ind, candidates, comb, target, ans);
        return ans;
    }
};
// @lc code=end
