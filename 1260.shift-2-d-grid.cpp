/*
 * @lc app=leetcode id=1260 lang=cpp
 *
 * [1260] Shift 2D Grid
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();
        int total_elements = m * n;

        // The effective number of shifts is k % total_elements.
        // If k is a multiple of total_elements, the grid doesn't change.
        k = k % total_elements;
        if (k == 0)
        {
            return grid;
        }

        vector<vector<int>> ans(m, vector<int>(n));

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                // 1. Calculate the 1D index of the current element.
                int original_1d_idx = i * n + j;

                // 2. Calculate the new 1D index after k shifts.
                int new_1d_idx = (original_1d_idx + k) % total_elements;

                // 3. Convert the new 1D index back to 2D coordinates.
                int new_row = new_1d_idx / n;
                int new_col = new_1d_idx % n;

                // 4. Place the element in the new grid.
                ans[new_row][new_col] = grid[i][j];
            }
        }
        return ans;
    }
};
// @lc code=end
