/*
 * @lc app=leetcode id=1608 lang=cpp
 *
 * [1608] Special Array With X Elements Greater Than or Equal X
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int specialArray(vector<int> &nums)
    {
        // int len = nums.size();
        // if (len == 0)
        //     return 0;
        // int x = -1;
        // int temp = 1;
        // while (temp <= len)
        // {
        //     int count = 0;
        //     for (int i = 0; i < len; i++)
        //     {
        //         if (nums[i] >= temp)
        //         {
        //             count++;
        //         }
        //     }
        //     if (temp == count)
        //     {
        //         x = temp;
        //         break;
        //     }
        //     temp++;
        // }
        // return x;

        // using binary search
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums[n - 1];
        int ans = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int cnt = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                if (nums[i] >= mid)
                {
                    cnt++;
                }
                else
                {
                    break;
                }
            }
            if (cnt == mid)
            {
                return mid;
            }
            else if (cnt > mid)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return ans;
    }
};
// @lc code=end
