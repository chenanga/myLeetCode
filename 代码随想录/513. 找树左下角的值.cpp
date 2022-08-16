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
 //     int findBottomLeftValue(TreeNode* root) {
 //         if (root->left == nullptr && root->right == nullptr)
 //             return root->val;
 //         __findBottomLeftValue(root, 1);
 //         return max_depth_left_value;
 //     }
 // private:
 //     int max_depth = 0;
 //     int max_depth_left_value;
 //     void __findBottomLeftValue(TreeNode* node, int depth) {
 //         if (node == nullptr) return;
 //         if (depth > max_depth) {
 //             max_depth = depth;
 //             max_depth_left_value = node->val;
 //         }
 //         __findBottomLeftValue(node->left, depth + 1);
 //         __findBottomLeftValue(node->right, depth + 1);

 //     }
 // };

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr)
            return root->val;
        int cur_val = 0, cur_depth = 0;
        __findBottomLeftValue(root, 1, cur_depth, cur_val);
        return cur_val;
    }
private:

    void __findBottomLeftValue(TreeNode* node, int depth, int& cur_depth, int& cur_val) {
        if (node == nullptr) return;
        if (depth > cur_depth) {
            cur_depth = depth;
            cur_val = node->val;
        }
        __findBottomLeftValue(node->left, depth + 1, cur_depth, cur_val);
        __findBottomLeftValue(node->right, depth + 1, cur_depth, cur_val);

    }
};