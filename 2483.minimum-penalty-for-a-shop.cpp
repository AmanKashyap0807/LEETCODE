/*
 * @lc app=leetcode id=2483 lang=cpp
 *
 * [2483] Minimum Penalty for a Shop
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    int bestClosingTime(string customers)
    {
        int n = customers.size();
        vector<int> prefixY(n + 1, 0);

        for (int i = 0; i < n; i++)
            prefixY[i + 1] = prefixY[i] + (customers[i] == 'Y');

        int totalY = prefixY[n];
        int minPenalty = INT_MAX, bestHour = 0;

        for (int j = 0; j <= n; j++)
        {
            int penalty = j + totalY - 2 * prefixY[j];
            if (penalty < minPenalty)
            {
                minPenalty = penalty;
                bestHour = j;
            }
        }

        return bestHour;
    }
};
// @lc code=end
