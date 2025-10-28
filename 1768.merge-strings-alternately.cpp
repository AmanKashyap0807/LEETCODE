/*
 * @lc app=leetcode id=1768 lang=cpp
 *
 * [1768] Merge Strings Alternately
 */

// @lc code=start
#include <string>
using namespace std;
class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string ans;
        int n = word1.size();
        int m = word2.size();
        int l = 0;
        int r = 0;
        int i = 0;
        while (l < n && r < m)
        {
            if (i % 2 == 0)
            {
                ans.push_back(word1[l++]);
            }
            else
            {
                ans.push_back(word2[r++]);
            }
            i++;
        }

        while (l < n)
        {
            ans.push_back(word1[l++]);
        }

        while (r < m)
        {
            ans.push_back(word2[r++]);
        }

        return ans;
    }
};
// @lc code=end
