#include "general.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
//  class Solution {
// public:
//     TreeNode* searchBST(TreeNode* root, int val) {
//         if (root == nullptr) return nullptr;
//         if (root->val == val) return root;
//         TreeNode* left = searchBST(root->left, val);
//         if (left != nullptr)
//             return left;
//         else
//             return searchBST(root->right, val);
//     }
// };

// ÓÅ»¯
// class Solution {
// public:
//     TreeNode* searchBST(TreeNode* root, int val) {
//         if (root == nullptr) return nullptr;
//         if (root->val == val) return root;
//         else if (root->val < val)
//             return searchBST(root->right, val);
//         else
//             return searchBST(root->left, val);
//     }
// };

// µü´ú
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) return nullptr;
        while (root != nullptr) {
            if (root->val == val)
                return root;
            else if (root->val < val)
                root = root->right;
            else
                root = root->left;
        }
        return nullptr;
    }
};