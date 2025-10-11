/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    void merge(vector<int> &n1, int m, vector<int> &n2, int n)
    {
        if (m == 0 && n == 0)
            return;
        if (m == 0)
        {
            n1 = n2;
            return;
        }
        if (n == 0)
        {
            return;
        }

        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0)
        {
            if (n1[i] == n2[j])
            {
                n1[k] = n1[i];
                k--;
                i--;
            }
            else if (n1[i] > n2[j])
            {
                n1[k] = n1[i];
                k--;
                i--;
            }
            else
            {
                n1[k] = n2[j];
                k--;
                j--;
            }
        }
        while (j >= 0)
        {
            n1[k] = n2[j];
            k--;
            j--;
        }
        return;
    }
};
// @lc code=end
