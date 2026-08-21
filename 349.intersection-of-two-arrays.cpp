/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> s(nums1.begin(), nums1.end());
        unordered_set<int> res;

        for (int i = 0; i < nums2.size(); i++)
        {
            if (s.count(nums2[i]))
            {
                if (!res.count(nums2[i]))
                {
                    res.insert(nums2[i]);
                }
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};
// @lc code=end
