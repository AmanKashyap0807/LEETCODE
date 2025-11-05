/*
 * @lc app=leetcode id=3033 lang=cpp
 *
 * [3033] Modify the Matrix
 */

// @lc code=start
#include <vector>
#include <algorithm> // For std::max
using namespace std;
class Solution
{
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        // Iterate through each column
        for (int j = 0; j < n; j++)
        {
            // 1. Find the maximum value in the current column 'j'
            int currentMax = -1; // Or INT_MIN
            for (int i = 0; i < m; i++)
            {
                currentMax = max(currentMax, matrix[i][j]);
            }

            // 2. Replace all -1s in the current column 'j' with the max value
            for (int i = 0; i < m; i++)
            {
                if (matrix[i][j] == -1)
                {
                    matrix[i][j] = currentMax;
                }
            }
        }
        return matrix;
    }
};
// @lc code=end
