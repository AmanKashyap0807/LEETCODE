/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 */

// @lc code=start
#include <vector>
#include <algorithm> // For std::swap
using namespace std;
class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int even_idx = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 0)
            {
                swap(nums[i], nums[even_idx]);
                even_idx++;
            }
        }
        return nums;
    }
};
// @lc code=end
