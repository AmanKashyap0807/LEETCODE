/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> ans;

        for (int x : nums)
        {
            int idx = abs(x) - 1;
            if (nums[idx] < 0)
                ans.push_back(abs(x)); // second visit → duplicate
            else
                nums[idx] = -nums[idx]; // mark as visited
        }

        return ans;
    }
};
// @lc code=end
