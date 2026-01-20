/*
 * @lc app=leetcode id=1329 lang=cpp
 *
 * [1329] Sort the Matrix Diagonally
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <functional>
using namespace std;
class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        unordered_map<int, vector<int>> diag_map;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                diag_map[i - j].push_back(mat[i][j]);
            }
        }
        for (auto &it : diag_map)
        {
            sort(it.second.begin(), it.second.end(), greater<int>());
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mat[i][j] = diag_map[i - j].back();
                diag_map[i - j].pop_back();
            }
        }
        return mat;
    }
};
// @lc code=end
