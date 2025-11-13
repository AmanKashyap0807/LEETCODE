/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> s;
        s.reserve(nums.size());
        for (int num : nums)
        {
            if (s.find(num) != s.end())
            {
                return true;
            }
            else
            {
                s.insert(num);
            }
        }
        return false;
    }
};
// @lc code=end
