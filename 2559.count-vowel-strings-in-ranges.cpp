/*
 * @lc app=leetcode id=2559 lang=cpp
 *
 * [2559] Count Vowel Strings in Ranges
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    bool isStringVowel(string &s)
    {
        if (s.empty())
            return false;
        if ((s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u') && (s[s.size() - 1] == 'a' || s[s.size() - 1] == 'e' || s[s.size() - 1] == 'i' || s[s.size() - 1] == 'o' || s[s.size() - 1] == 'u'))
        {
            return true;
        }
        return false;
    }

    vector<int>
    vowelStrings(vector<string> &words, vector<vector<int>> &queries)
    {
        int n = words.size();
        vector<int> psm;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                if (isStringVowel(words[i]))
                {
                    psm.push_back(1);
                }
                else
                {
                    psm.push_back(0);
                }
            }
            else
            {
                if (isStringVowel(words[i]))
                {
                    psm.push_back(psm[i - 1] + 1);
                }
                else
                {
                    psm.push_back(psm[i - 1]);
                }
            }
        }

        int m = queries.size();
        vector<int> ans;
        for (int i = 0; i < m; i++)
        {
            if (queries[i][0] == 0)
            {
                ans.push_back(psm[queries[i][1]]);
            }
            else
            {
                ans.push_back(psm[queries[i][1]] - psm[queries[i][0] - 1]);
            }
        }
        return ans;
    }
};
// @lc code=end
