/*
 * @lc app=leetcode id=1748 lang=cpp
 *
 * [1748] Sum of Unique Elements
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int sumOfUnique(vector<int> &nums)
    {
        unordered_map<int, int> cnt;
        cnt.reserve(nums.size());
        for (int num : nums)
        {
            cnt[num]++;
        }
        int sum = 0;
        for (auto it = cnt.begin(); it != cnt.end(); it++)
        {
            if (it->second == 1)
            {
                sum += it->first;
            }
        }
        return sum;
    }
    // There is also one pass method for solving this question
    // int sumOfUnique(vector<int>& nums) {
    //     unordered_map<int,int> cnt;
    //     cnt.reserve(nums.size()*2);
    //     int sum = 0;
    //     for (int x : nums) {
    //         int c = ++cnt[x];
    //         if (c == 1) sum += x;   // first time seen
    //         else if (c == 2) sum -= x; // became non-unique, remove previously added value
    //     }
    //     return sum;
    // }

    // there is also frequency array method for solving this question
    // int sumOfUnique(vector<int> &nums)
    // {
    //     int freq[101] = {0};
    //     for (int x : nums)
    //         ++freq[x];
    //     int sum = 0;
    //     for (int v = 1; v <= 100; ++v)
    //     {
    //         if (freq[v] == 1)
    //             sum += v;
    //     }
    //     return sum;
    // }
};
// @lc code=end
