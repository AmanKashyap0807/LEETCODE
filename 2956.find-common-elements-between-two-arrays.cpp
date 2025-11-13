/*
 * @lc app=leetcode id=2956 lang=cpp
 *
 * [2956] Find Common Elements Between Two Arrays
 */

// @lc code=start
#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    vector<int> findIntersectionValues(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> s1, s2;
        s1.reserve(nums1.size() * 2);
        s2.reserve(nums2.size() * 2);
        s1.insert(nums1.begin(), nums1.end());
        s2.insert(nums2.begin(), nums2.end());

        int ans1 = 0;
        for (int num : nums1)
        {
            if (s2.count(num))
            {
                ans1++;
            }
        }
        int ans2 = 0;
        for (int num : nums2)
        {
            if (s1.count(num))
            {
                ans2++;
            }
        }
        return {ans1, ans2};
    }
};
// @lc code=end
