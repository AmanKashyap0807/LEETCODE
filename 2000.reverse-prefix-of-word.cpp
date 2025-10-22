/*
 * @lc app=leetcode id=2000 lang=cpp
 *
 * [2000] Reverse Prefix of Word
 */

// @lc code=start
#include <string>
using namespace std;
class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        if (word.empty())
            return word;

        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] == ch)
            {
                for (int j = 0; j <= i / 2; j++)
                {
                    swap(word[j], word[i - j]);
                }
                break;
            }
        }
        return word;
    }
};
// @lc code=end
