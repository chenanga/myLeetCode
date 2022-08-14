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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> res;
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size - 1; ++i) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            TreeNode* node = que.front();
            res.push_back(node->val);
            que.pop();
            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);

        }
        return res;

    }
};