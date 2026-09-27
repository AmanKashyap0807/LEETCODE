/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    void solve(int ind, vector<int> &cand, vector<int> &comb, int t, vector<vector<int>> &ans)
    {
        // Why not go ahead and check for other values if they sum to t?
        // Because the ind means we chose the previous values already in that case
        if (t == 0)
        {
            ans.push_back(comb);
            return;
        }

        if (t < 0)
            return;

        // default
        if (ind >= cand.size())
        {
            return;
        }

        for (int i = ind; i < cand.size(); i++)
        {
            if (i > ind && cand[i] == cand[i - 1])
                continue;

            if (cand[i] > t)
                break;

            comb.push_back(cand[i]);
            solve(i + 1, cand, comb, t - cand[i], ans);
            comb.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> comb;
        int ind = 0;
        solve(ind, candidates, comb, target, ans);
        return ans;
    }
};
// @lc code=end
