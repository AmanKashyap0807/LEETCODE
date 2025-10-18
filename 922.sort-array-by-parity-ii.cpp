/*
 * @lc app=leetcode id=922 lang=cpp
 *
 * [922] Sort Array By Parity II
 */

// @lc code=start
#include <vector>
#include <algorithm> // For std::swap
using namespace std;
class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &nums)
    {
        int n = nums.size();
        int even_idx = 0;
        int odd_idx = 1;
        while (even_idx < n && odd_idx < n)
        {
            // Move even_idx to the next even index with an odd value
            while (even_idx < n && nums[even_idx] % 2 == 0)
            {
                even_idx += 2;
            }
            // Move odd_idx to the next odd index with an even value
            while (odd_idx < n && nums[odd_idx] % 2 != 0)
            {
                odd_idx += 2;
            }
            // Swap if both pointers are valid
            if (even_idx < n && odd_idx < n)
            {
                swap(nums[even_idx], nums[odd_idx]);
            }
        }
        return nums;
    }
};
// @lc code=end
