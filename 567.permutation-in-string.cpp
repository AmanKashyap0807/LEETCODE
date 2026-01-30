/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();
        if (m < n)
            return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        for (int i = 0; i < n; i++)
        {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        int l = 0;
        int h = n - 1;
        while (h < m)
        {
            int i = 0;
            while (i < 26)
            {
                if (freq1[i] != freq2[i])
                {
                    break;
                }
                i++;
            }
            if (i == 26)
            {
                return true;
            }
            freq2[s2[l] - 'a']--;
            l++;
            h++;
            if (h < m)
            {
                freq2[s2[h] - 'a']++;
            }
        }
        return false;
    }
};
// @lc code=end
