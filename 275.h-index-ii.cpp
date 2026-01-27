/*
 * @lc app=leetcode id=275 lang=cpp
 *
 * [275] H-Index II
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        if (citations.empty())
            return 0;
        int ans = 0;
        int low = 0;
        int len = citations.size();
        int high = len - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (len - mid <= citations[mid])
            {
                ans = len - mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};
// @lc code=end
