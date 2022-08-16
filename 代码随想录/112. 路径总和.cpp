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
 //     bool hasPathSum(TreeNode* root, int targetSum) {
 //        return __hasPathSum(root, targetSum, 0);
 //     }
 // private:
 //     bool __hasPathSum(TreeNode* node, int targetSum, int curSum) {
 //         if (node == nullptr) return false;
 //         if (node->left == nullptr && node->right == nullptr) {
 //             if (curSum + node->val == targetSum)
 //                 return true;
 //             else
 //                 return false;
 //         } else {
 //             return __hasPathSum(node->left, targetSum, curSum + node->val) || __hasPathSum(node->right, targetSum, curSum + node->val);
 //         }

 //     }
 // };


class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        else if (root->left == nullptr && root->right == nullptr) return root->val == targetSum;
        else return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};