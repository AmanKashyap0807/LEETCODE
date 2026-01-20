/*
 * @lc app=leetcode id=1941 lang=cpp
 *
 * [1941] Check if All Characters Have Equal Number of Occurrences
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    bool areOccurrencesEqual(string s)
    {
        // unordered_map<char, int> m;
        // for (char c : s)
        // {
        //     m[c]++;
        // }
        // int occ = m[s[0]];
        // for (auto &it : m)
        // {
        //     if (it.second != occ)
        //     {
        //         return false;
        //     }
        // }
        // return true;

        // more optimized for space complexity withou
        vector<int> alpha(26, 0);
        for (char c : s)
        {
            alpha[c - 'a']++;
        }
        int occ = 0;
        int i = 0;
        while (i < 26)
        {
            if (alpha[i] != 0)
            {
                occ = alpha[i];
                break;
            }
            i++;
        }
        for (int j = i + 1; j < 26; j++)
        {
            if (alpha[j] != occ && alpha[j] != 0)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
