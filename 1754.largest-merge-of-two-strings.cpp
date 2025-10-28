/*
 * @lc app=leetcode id=1754 lang=cpp
 *
 * [1754] Largest Merge Of Two Strings
 */

// @lc code=start
#include <string>
using namespace std;
class Solution
{
public:
    string largestMerge(string word1, string word2)
    {
        string ans;
        int l = 0;
        int r = 0;
        int n = word1.size();
        int m = word2.size();
        while (l < n && r < m)
        {
            if (word1[l] > word2[r])
            {
                ans.push_back(word1[l++]);
            }
            else if (word1[l] < word2[r])
            {
                ans.push_back(word2[r++]);
            }
            else
            {
                if (word1.substr(l) > word2.substr(r))
                {
                    ans.push_back(word1[l++]);
                }
                else
                {
                    ans.push_back(word2[r++]);
                }
            }
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
