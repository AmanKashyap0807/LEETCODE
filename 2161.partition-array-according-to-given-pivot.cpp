/*
 * @lc app=leetcode id=2161 lang=cpp
 *
 * [2161] Partition Array According to Given Pivot
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        int n = nums.size();
        if (n == 0)
            return {};
        int l = -1;
        int r = n;
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < pivot)
            {
                l++;
                ans[l] = nums[i];
            }
            else if (nums[i] > pivot)
            {
                r--;
                ans[r] = nums[i];
            }
        }
        l++;
        while (l < r)
        {
            ans[l] = pivot;
            l++;
        }
        int j = n - 1;
        while (r < j)
        {
            swap(ans[r], ans[j]);
            r++;
            j--;
        }
        return ans;
    }
};
// @lc code=end
