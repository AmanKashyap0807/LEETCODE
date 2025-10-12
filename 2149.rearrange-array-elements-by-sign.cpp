/*
 * @lc app=leetcode id=2149 lang=cpp
 *
 * [2149] Rearrange Array Elements by Sign
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        if (nums.empty())
            return {};

        //------------------------------------------------
        // brute force approch
        // int n = nums.size();
        // vector<int> ans;
        // int pind = 0, nind = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     if (i % 2 == 0)
        //     {
        //         for (int j = pind; j < n; j++)
        //         {
        //             if (nums[j] >= 0)
        //             {
        //                 ans.push_back(nums[j]);
        //                 pind = j + 1;
        //                 break;
        //             }
        //         }
        //     }
        //     else
        //     {
        //         for (int j = nind; j < n; j++)
        //         {
        //             if (nums[j] < 0)
        //             {
        //                 ans.push_back(nums[j]);
        //                 nind = j + 1;
        //                 break;
        //             }
        //         }
        //     }
        // }
        // return ans;

        //------------------------------------------------
        // optimized approch
        int n = nums.size();
        vector<int> ans(n);
        vector<int> arr(n);
        int p = 0, ne = n - 1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] >= 0)
            {
                arr[p] = nums[i];
                p++;
            }
            else
            {
                arr[ne] = nums[i];
                ne--;
            }
        }
        p--;
        ne++;
        for (int i = n - 1; i >= 0; i--)
        {
            if (i % 2 == 0)
            {
                ans[i] = arr[p];
                p--;
            }
            else
            {
                ans[i] = arr[ne];
                ne++;
            }
        }
        return ans;
    }
};
// @lc code=end
