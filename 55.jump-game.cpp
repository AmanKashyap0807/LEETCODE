/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int goal = n - 1;
        // we will have goal as last index and we will backtract from there updating
        // as we see the the prev index can reach the goal
        for (int i = n - 2; i >= 0; i--)
        {
            if (i + nums[i] >= goal)
            {
                goal = i;
            }
        }
        if (goal == 0)
            return true;
        else
            return false;
    }
};
// @lc code=end
