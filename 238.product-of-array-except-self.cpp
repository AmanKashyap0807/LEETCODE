/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> leftp;
        leftp.push_back(nums[0]);
        for (int i = 1; i < n; i++)
        {
            leftp.push_back(nums[i] * leftp[i - 1]);
        }

        vector<int> rightp;
        rightp.push_back(nums[n - 1]);
        int j = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            rightp.push_back(rightp[j] * nums[i]);
            j++;
        }

        vector<int> ans;
        ans.push_back(rightp[n - 2]);
        for (int i = 1; i < n - 1; i++)
        {
            ans.push_back(leftp[i - 1] * rightp[n - 2 - i]);
        }
        ans.push_back(leftp[n - 2]);

        return ans;
    }
};
// @lc code=end
