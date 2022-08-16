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
  //     bool isBalanced(TreeNode* root) {
  //         if (root == nullptr) return true;
  //         if (isBalanced(root->left) && isBalanced(root->right) && abs(getDepth(root->left) - getDepth(root->right)) <= 1)
  //             return true;
  //         else
  //             return false;
  //     }
  // private:
  //     int getDepth(TreeNode* node) {
  //         if (node == nullptr) return 0;
  //         int left = getDepth(node->left);
  //         int right = getDepth(node->right);
  //         return 1 + max(left, right);

  //     }
  // };


class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;

        return getDepth(root) >= 0;
    }
private:
    int getDepth(TreeNode* node) {
        if (node == nullptr) return 0;

        int left = getDepth(node->left);
        int right = getDepth(node->right);
        if (left == -1 || right == -1 || abs(left - right) > 1)
            return -1;

        return 1 + max(left, right);

    }
};