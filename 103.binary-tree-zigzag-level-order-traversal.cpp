/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == NULL)
        {
            return res;
        }

        queue<TreeNode *> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty())
        {
            int s = q.size();
            vector<int> row(s);
            for (int i = 0; i < s; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                int index = (leftToRight) ? i : (s - 1 - i);
                row[index] = node->val;
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
            leftToRight = !leftToRight;
            res.push_back(row);
        }
        return res;
    }
};
// @lc code=end
