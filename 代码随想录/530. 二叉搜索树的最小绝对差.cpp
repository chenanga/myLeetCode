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
    int getMinimumDifference(TreeNode* root) {
        // ×óÖĞÓÒ±éÀú
        __getMinimumDifference(root);
        return res;
    }
private:
    int res = INT_MAX;
    TreeNode* pre_ = nullptr;
    void __getMinimumDifference(TreeNode* cur) {
        if (cur == nullptr) return;
        __getMinimumDifference(cur->left);
        if (pre_ != nullptr) {
            res = min(res, abs(pre_->val - cur->val));
        }
        pre_ = cur;
        __getMinimumDifference(cur->right);
        return;
    }
};