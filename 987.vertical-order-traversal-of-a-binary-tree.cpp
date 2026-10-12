/*
 * @lc app=leetcode id=987 lang=cpp
 *
 * [987] Vertical Order Traversal of a Binary Tree
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
#include <map>
#include <queue>
#include <set>
#include <utility>
using namespace std;
class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode *, pair<int, int>>> todo;
        todo.push({root, {0, 0}});
        while (!todo.empty())
        {
            auto p = todo.front();
            todo.pop();
            TreeNode *node = p.first;
            int x = p.second.first;
            int y = p.second.second;
            nodes[x][y].insert(node->val);
            if (node->left)
            {
                todo.push({node->left, {x - 1, y + 1}});
            }
            if (node->right)
            {
                todo.push({node->right, {x + 1, y + 1}});
            }
        }
        for (auto p : nodes)
        {
            vector<int> col;
            for (auto q : p.second)
            {
                // col.push_back(q.second.begin(), q.second.end());
                // push_back() accepts only one element, not a range of elements.
                // Since q.second is a multiset<int>, use insert() to append its entire range to the vector:
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};
// @lc code=end
