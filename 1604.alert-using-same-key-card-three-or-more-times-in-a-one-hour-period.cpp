/*
 * @lc app=leetcode id=1604 lang=cpp
 *
 * [1604] Alert Using Same Key-Card Three or More Times in a One Hour Period
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution
{
    int toMin(const string &t)
    {
        int h = (t[0] - '0') * 10 + (t[1] - '0');
        int m = (t[3] - '0') * 10 + (t[4] - '0');
        return h * 60 + m;
    }

public:
    vector<string> alertNames(vector<string> &keyName, vector<string> &keyTime)
    {
        unordered_map<string, vector<int>> mp;
        for (int i = 0; i < keyName.size(); i++)
        {
            mp[keyName[i]].push_back(toMin(keyTime[i]));
        }

        vector<string> alerted;
        for (auto &entry : mp)
        {
            const string &name = entry.first;
            auto &times = entry.second;
            sort(times.begin(), times.end()); // lex sort would also work on "HH:MM", but we use minutes

            // Check any 3 uses within 60 minutes inclusive
            for (int i = 0; i + 2 < (int)times.size(); ++i)
            {
                if (times[i + 2] - times[i] <= 60)
                {
                    alerted.push_back(name);
                    break;
                }
            }
        }
        sort(alerted.begin(), alerted.end()); // alphabetical order
        return alerted;
    }
};
// @lc code=end
