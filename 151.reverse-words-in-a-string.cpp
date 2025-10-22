/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
#include <string>
#include <vector>
#include <algorithm> // For std::reverse
using namespace std;
class Solution
{
public:
    string reverseWords(string s)
    {
        // non inplace solution with best time complexity O(n) and space complexity O(n)
        // if (s.empty())
        //     return s;
        // vector<string> words;
        // string temp;
        // for (int i = 0; i < s.size(); i++)
        // {
        //     if (s[i] == ' ' && !temp.empty())
        //     {
        //         words.push_back(temp);
        //         temp.clear();
        //     }
        //     else if (s[i] == ' ' && temp.empty())
        //     {
        //         continue;
        //     }
        //     else
        //     {
        //         temp.push_back(s[i]);
        //     }
        // }
        // if (!temp.empty())
        // {
        //     words.push_back(temp);
        // }
        // string ans;
        // for (int i = words.size() - 1; i >= 0; i--)
        // {
        //     ans += words[i];
        //     if (i != 0)
        //     {
        //         ans.push_back(' ');
        //     }
        // }
        // return ans;

        //-------------------------------------------------------
        // inplace solution with time complexity O(n) and space complexity O(1)
        // Step 1: Clean up spaces in-place.
        // Use a write pointer 'j' to build the clean string at the beginning of s.
        int j = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            // Skip leading spaces
            if (s[i] == ' ')
                continue;

            // If it's not the first word, add a single space before it.
            if (j != 0)
            {
                s[j++] = ' ';
            }

            // Copy the word.
            while (i < s.length() && s[i] != ' ')
            {
                s[j++] = s[i++];
            }
            // The outer loop's i++ will handle the space, so we need to go back one.
            i--;
        }
        // Resize the string to its new, clean length.
        s.resize(j);

        // Step 2: Reverse the entire string.
        // "the sky is blue" -> "eulb si yks eht"
        reverse(s.begin(), s.end());

        // Step 3: Reverse each word individually.
        int start = 0;
        for (int end = 0; end <= s.length(); ++end)
        {
            // Find the end of a word (either a space or the end of the string).
            if (end == s.length() || s[end] == ' ')
            {
                // Reverse the word from 'start' to 'end'.
                reverse(s.begin() + start, s.begin() + end);
                // Move 'start' to the beginning of the next word.
                start = end + 1;
            }
        }

        return s;
    }
};
// @lc code=end
