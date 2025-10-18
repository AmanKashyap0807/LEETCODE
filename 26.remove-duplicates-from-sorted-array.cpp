/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int count = 0;
        int ind = -1;
        int curr = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != curr)
            {
                count++;
                ind++;
                nums[ind] = nums[i];
                curr = nums[i];
            }
        }
        return count;
    }
};
// @lc code=end
