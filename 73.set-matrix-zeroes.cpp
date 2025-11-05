/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        bool isRowZero = false; // Does the first row itself need to be zeroed?
        bool isColZero = false; // Does the first col itself need to be zeroed?

        // 1. Check if the first column has any zeros
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][0] == 0)
            {
                isColZero = true;
                break;
            }
        }

        // 2. Check if the first row has any zeros
        for (int j = 0; j < m; j++)
        {
            if (matrix[0][j] == 0)
            {
                isRowZero = true;
                break;
            }
        }

        // 3. Use the first row and col as markers for the rest of the matrix
        // Start from (1,1) to avoid corrupting the markers prematurely
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0; // Mark the row
                    matrix[0][j] = 0; // Mark the column
                }
            }
        }

        // 4. Zero out cells based on the markers in the first row and col
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // 5. Finally, zero out the first row if needed
        if (isRowZero)
        {
            for (int j = 0; j < m; j++)
            {
                matrix[0][j] = 0;
            }
        }

        // 6. Finally, zero out the first column if needed
        if (isColZero)
        {
            for (int i = 0; i < n; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};
// @lc code=end
