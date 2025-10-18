/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int j = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                j++;
                nums[j] = nums[i];
            }
        }
        return j + 1;
    }
};
// @lc code=end
