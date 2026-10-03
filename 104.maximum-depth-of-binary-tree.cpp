/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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

void solve(int cnt, int &maxi, TreeNode *node)
{
    if (node == NULL)
    {
        return;
    }
    cnt++;
    maxi = max(maxi, cnt);
    solve(cnt, maxi, node->left);
    solve(cnt, maxi, node->right);
}

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        int cnt = 0;
        int maxi = 0;
        TreeNode *node = root;
        solve(cnt, maxi, node);
        return maxi;
    }
};
// @lc code=end
