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
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> res;
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            int size = que.size();
            int max_num = INT_MIN;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                if (node->val > max_num) max_num = node->val;
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            res.push_back(max_num);

        }
        return res;
    }
};