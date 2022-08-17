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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        return __isValidBST(root, LONG_MIN, LONG_MAX);
    }
private:
    // (left, right)
    bool __isValidBST(TreeNode* root, long long left, long long right) {
        if (root == nullptr) return true;
        if (root->val > left && root->val < right) {
            return __isValidBST(root->left, left, root->val) && __isValidBST(root->right, root->val, right);
        }
        else {
            return false;
        }

    }
};