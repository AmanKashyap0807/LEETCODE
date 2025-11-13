/*
 * @lc app=leetcode id=2100 lang=cpp
 *
 * [2100] Find Good Days to Rob the Bank
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> goodDaysToRobBank(vector<int> &security, int time)
    {
        int n = security.size();
        if (time == 0)
        {
            vector<int> allDays(n);
            iota(allDays.begin(), allDays.end(), 0);
            return allDays;
        }

        if (n < 2 * time + 1)
            return {};

        vector<int> left(n, 0), right(n, 0);

        // Compute left[i] = number of consecutive non-increasing days ending at i
        for (int i = 1; i < n; i++)
        {
            if (security[i - 1] >= security[i])
                left[i] = left[i - 1] + 1;
        }

        // Compute right[i] = number of consecutive non-decreasing days starting at i
        for (int i = n - 2; i >= 0; i--)
        {
            if (security[i] <= security[i + 1])
                right[i] = right[i + 1] + 1;
        }

        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            if (left[i] >= time && right[i] >= time)
                res.push_back(i);
        }

        return res;
    }
};
// @lc code=end
