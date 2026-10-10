/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <iostream>
using namespace std;
class Solution
{
public:
    int solve(TreeNode *node, int &maxi)
    {
        if (node == NULL)
        {
            return 0;
        }
        int ls = solve(node->left, maxi);
        int rs = solve(node->right, maxi);
        int total = ls + rs + node->val;
        int lsv = ls + node->val;
        int rsv = rs + node->val;
        maxi = max(max(max(max(maxi, total), lsv), rsv), node->val);
        return max(max(ls + node->val, rs + node->val), 0);
    }

    int maxPathSum(TreeNode *root)
    {
        int maxi = INT_MIN;
        int temp = solve(root, maxi);
        return maxi;
    }
};
// @lc code=end
