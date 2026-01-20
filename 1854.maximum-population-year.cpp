/*
 * @lc app=leetcode id=1854 lang=cpp
 *
 * [1854] Maximum Population Year
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int maximumPopulation(vector<vector<int>> &logs)
    {
        // int maxPYear = -1;
        // int maxPoYear = -1;
        // for (int i = 1950; i <= 2050; i++)
        // {
        //     int count = 0;
        //     for (int j = 0; j < logs.size(); j++)
        //     {
        //         if (i >= logs[j][0] && i < logs[j][1])
        //         {
        //             count++;
        //         }
        //     }
        //     if (count > maxPoYear)
        //     {
        //         maxPoYear = count;
        //         maxPYear = i;
        //     }
        // }
        // return maxPYear;

        vector<int> yearBirthDeath(101, 0);
        for (int i = 0; i < logs.size(); i++)
        {
            yearBirthDeath[logs[i][0] - 1950]++;
            yearBirthDeath[logs[i][1] - 1950]--;
        }
        int maxp = yearBirthDeath[0];
        int maxyear = 0;
        for (int i = 1; i < 101; i++)
        {
            yearBirthDeath[i] += yearBirthDeath[i - 1];
            if (yearBirthDeath[i] > maxp)
            {
                maxp = yearBirthDeath[i];
                maxyear = i;
            }
        }
        return maxyear + 1950;
    }
};
// @lc code=end
