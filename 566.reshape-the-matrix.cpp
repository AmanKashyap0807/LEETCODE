/*
 * @lc app=leetcode id=566 lang=cpp
 *
 * [566] Reshape the Matrix
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        // --------------------------------------------------
        // Brute force approch
        // if (mat.size() * mat[0].size() != r * c)
        //     return mat;
        // vector<int> flat;
        // // In 2d vector number of rows = mat.size()
        // // number of columns = mat[0].size()
        // for (int i = 0; i < mat.size(); i++)
        // {
        //     for (int j = 0; j < mat[0].size(); j++)
        //     {
        //         flat.push_back(mat[i][j]);
        //     }
        // }

        // vector<vector<int>> ans(r, vector<int>(c));
        // for (int i = 0; i < r; i++)
        // {
        //     for (int j = 0; j < c; j++)
        //     {
        //         ans[i][j] = flat[i * c + j];
        //     }
        // }
        // return ans;

        // --------------------------------------------------
        // n squre to n time complexity and o(1) space complexity approch
        int m = mat.size(), n = mat[0].size();
        if (m * n != r * c)
            return mat;

        vector<vector<int>> ans(r, vector<int>(c));
        for (int k = 0; k < r * c; ++k)
        {
            ans[k / c][k % c] = mat[k / n][k % n];
        }
        return ans;
        // --------------------------------------------------
        // the flatten approch was better as due to some reason the run time
        // is flatten approch is better then this approch
        // most probabily due to the sequenceal way to retrive data from 2d array
    }
};
// @lc code=end
