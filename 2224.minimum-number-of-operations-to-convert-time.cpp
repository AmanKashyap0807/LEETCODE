/*
 * @lc app=leetcode id=2224 lang=cpp
 *
 * [2224] Minimum Number of Operations to Convert Time
 */

// @lc code=start
#include <string>
using namespace std;
class Solution
{
public:
    int getTimeMinutes(string &time)
    {
        string hourPart = time.substr(0, 2);
        string minutePart = time.substr(3, 2);
        int hours = stoi(hourPart);
        int minutes = stoi(minutePart);
        return hours * 60 + minutes;
    }

    int convertTime(string current, string correct)
    {
        int currentTime = getTimeMinutes(current);
        int correctTime = getTimeMinutes(correct);
        int diff = correctTime - currentTime;
        int count = 0;
        if (diff == 0)
        {
            return 0;
        }
        else if (diff < 0)
        {
            diff = 1439 + diff;
        }

        if (diff >= 60)
        {
            count += diff / 60;
            diff = diff % 60;
        }
        if (diff < 60 && diff >= 15)
        {
            count += diff / 15;
            diff = diff % 15;
        }
        if (diff < 15 && diff >= 5)
        {
            count += diff / 5;
            diff = diff % 5;
        }
        if (diff < 5 && diff >= 1)
        {
            count += diff / 1;
            diff = diff % 1;
        }
        return count;
    }
};
// @lc code=end
