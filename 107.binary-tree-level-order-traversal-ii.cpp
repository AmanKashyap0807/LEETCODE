/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
        {
            return ans;
        }
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        int level = 0;
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                level++;
                if (!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                if (ans.size() <= level)
                {
                    ans.push_back({});
                }
                ans[level].push_back(temp->val);
                if (temp->left != NULL)
                {
                    q.push(temp->left);
                }
                if (temp->right != NULL)
                {
                    q.push(temp->right);
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
