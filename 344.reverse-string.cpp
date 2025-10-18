/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        if (s.size() == 0)
            return;
        for (int i = 0; i < s.size() / 2; i++)
        {
            swap(s[i], s[s.size() - 1 - i]);
        }
    }
};
// @lc code=end
