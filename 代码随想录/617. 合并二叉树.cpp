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
 // class Solution {
 // public:
 //     TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
 //         return __mergeTrees(root1, root2);
 //     }
 // private:
 //     TreeNode* __mergeTrees(TreeNode* root1, TreeNode* root2) {
 //         if (root1 == nullptr && root2 == nullptr) return nullptr;
 //         TreeNode* newnode = nullptr;
 //         if (root1 == nullptr) {
 //             newnode = new TreeNode(root2->val);
 //             newnode->left = __mergeTrees(root1, root2->left);
 //             newnode->right = __mergeTrees(root1, root2->right);
 //         } else if (root2 == nullptr) {
 //             newnode = new TreeNode(root1->val);
 //             newnode->left = __mergeTrees(root1->left, root2);
 //             newnode->right = __mergeTrees(root1->right, root2);
 //         } else {
 //             newnode = new TreeNode(root1->val + root2->val);
 //             newnode->left = __mergeTrees(root1->left, root2->left);
 //             newnode->right = __mergeTrees(root1->right, root2->right);
 //         }
 //         return newnode;
 //     }
 // };

 // ÀûÓÃroot1
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return __mergeTrees(root1, root2);
    }
private:
    TreeNode* __mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) return nullptr;
        if (root1 == nullptr) {
            return root2;
        }
        else if (root2 == nullptr) {
            return root1;
        }
        else {
            root1->val = root1->val + root2->val;
            root1->left = __mergeTrees(root1->left, root2->left);
            root1->right = __mergeTrees(root1->right, root2->right);
            return root1;
        }
    }
};