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
 //     vector<int> postorderTraversal(TreeNode* root) {
 //         __postorderTraversal(root);
 //         return res_;
 //     }
 // private:
 //     vector<int> res_;

 //     void __postorderTraversal(TreeNode* node) {
 //         if (node == nullptr)
 //             return;

 //         __postorderTraversal(node->left);
 //         __postorderTraversal(node->right);
 //         res_.push_back(node->val);

 //         return;

 //     }
 // };


 // µü´ú·¨
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr)
            return {};
        vector<int> res;
        stack<TreeNode*> stc;
        TreeNode* node = root;
        TreeNode* pre = nullptr;
        while (node != nullptr || !stc.empty()) {
            while (node != nullptr) {
                stc.push(node);
                node = node->left;
            }
            node = stc.top();
            stc.pop();

            if (node->right == nullptr || node->right == pre) {
                res.push_back(node->val);
                pre = node;
                node = nullptr;
            }
            else {
                stc.push(node);
                node = node->right;
            }
        }

        return res;
    }
};
