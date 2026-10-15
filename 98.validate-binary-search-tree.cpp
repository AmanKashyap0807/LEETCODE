/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
#include <climits>
using namespace std;
class Solution
{
public:
    bool solve(TreeNode *node, long long l, long long h)
    {
        if (node == NULL)
        {
            return true;
        }
        if (node->val > l && node->val < h)
        {
            if (!solve(node->left, l, node->val))
            {
                return false;
            }
            if (!solve(node->right, node->val, h))
            {
                return false;
            }
        }
        else
        {
            return false;
        }
        return true;
    }

    bool isValidBST(TreeNode *root)
    {
        long long l = LLONG_MIN;
        long long h = LLONG_MAX;
        return solve(root, l, h);
    }
};
// @lc code=end
