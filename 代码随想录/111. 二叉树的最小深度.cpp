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
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr)
            return 1;

        int min_depth = INT_MAX;
        if (root->left != nullptr)
            min_depth = min(min_depth, minDepth(root->left));
        if (root->right != nullptr)
            min_depth = min(min_depth, minDepth(root->right));

        return 1 + min_depth;
    }
};