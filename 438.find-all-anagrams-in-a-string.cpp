/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        // int n = s.size();
        // int m = p.size();
        // vector<int> ans;
        // if (n < m)
        // {
        //     return ans;
        // }
        // vector<int> v(26, 0);
        // int st = 0;
        // int l = m - 1;
        // while (l < n)
        // {
        //     bool flag = true;
        //     for (int i = 0; i < m; i++)
        //     {
        //         v[(s[st + i] - 'a')]++;
        //         v[(p[i] - 'a')]--;
        //     }
        //     for (int i = 0; i < 26; i++)
        //     {
        //         if (v[i] != 0)
        //         {
        //             flag = false;
        //             break;
        //         }
        //     }
        //     for (int i = 0; i < 26; i++)
        //     {
        //         v[i] = 0;
        //     }
        //     if (flag)
        //     {
        //         ans.push_back(st);
        //     }
        //     st++;
        //     l++;
        // }
        // return ans;

        // more optimized with two frequency array
        vector<int> ans;
        int n = s.size(), m = p.size();
        if (n < m)
            return ans;

        vector<int> freqP(26, 0), freqS(26, 0);

        // frequency of p
        for (char c : p)
        {
            freqP[c - 'a']++;
        }

        int left = 0;
        for (int right = 0; right < n; right++)
        {
            freqS[s[right] - 'a']++;

            // keep window size = m
            if (right - left + 1 > m)
            {
                freqS[s[left] - 'a']--;
                left++;
            }

            if (freqS == freqP)
            {
                ans.push_back(left);
            }
        }
        return ans;
    }
};
// @lc code=end
