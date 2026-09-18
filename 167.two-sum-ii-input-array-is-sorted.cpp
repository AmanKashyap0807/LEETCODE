/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right)
        {
            int s = numbers[left] + numbers[right];
            if (s < target)
            {
                left++;
            }
            else if (s > target)
            {
                right--;
            }
            else
            {
                return {left + 1, right + 1};
            }
        }
        return {};
    }
};
// @lc code=end
