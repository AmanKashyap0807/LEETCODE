/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */

// @lc code=start
#include <vector>
using namespace std;
class NumMatrix
{
private:
    vector<vector<int>> psm;

public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
        {
            return;
        }
        psm.resize(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (i == 0 && j == 0)
                {
                    psm[i][j] = matrix[i][j];
                }
                else if (i == 0)
                {
                    psm[i][j] = matrix[i][j] + psm[i][j - 1];
                }
                else if (j == 0)
                {
                    psm[i][j] = matrix[i][j] + psm[i - 1][j];
                }
                else
                {
                    psm[i][j] = matrix[i][j] + psm[i][j - 1] + psm[i - 1][j] - psm[i - 1][j - 1];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        if (row1 == 0 && col1 == 0)
        {
            return psm[row2][col2];
        }
        else if (row1 == 0)
        {
            return psm[row2][col2] - psm[row2][col1 - 1];
        }
        else if (col1 == 0)
        {
            return psm[row2][col2] - psm[row1 - 1][col2];
        }
        else
        {
            return psm[row2][col2] - psm[row2][col1 - 1] - psm[row1 - 1][col2] + psm[row1 - 1][col1 - 1];
        }
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
