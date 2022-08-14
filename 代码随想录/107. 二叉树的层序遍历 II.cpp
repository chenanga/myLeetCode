#include "general.h"

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
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> v(size, 0);
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();
                v[i] = node->val;
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);

            }
            res.push_back(v);

        }
        reverse(res.begin(), res.end());
        return res;
    }
};