#include "general.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
//     {
//         if (root == nullptr || root == p || root == q) return root;
//
//         TreeNode* left = lowestCommonAncestor(root->left, p, q);
//         TreeNode* right = lowestCommonAncestor(root->right, p, q);
//
//         if (left == nullptr)
//             return right;
//         else if (right == nullptr)
//             return left;
//
//         return root;
//     }
// };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) return root;
        if (root->val > q->val && root->val > p->val) {
            return lowestCommonAncestor(root->left, p, q);

        } else if (root->val < q->val && root->val < p->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            TreeNode* left = lowestCommonAncestor(root->left, p, q);
            TreeNode* right = lowestCommonAncestor(root->right, p, q);
            if (left == nullptr)
                return right;
            else if (right == nullptr)
                return left;
        }

        return root;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val > q->val && root->val > p->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (root->val < q->val && root->val < p->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return root;
        }
    }
};