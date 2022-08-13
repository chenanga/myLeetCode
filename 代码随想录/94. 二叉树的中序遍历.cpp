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
 //     vector<int> inorderTraversal(TreeNode* root) {
 //         __inorderTraversal(root);
 //         return res_;
 //     }
 // private:
 //     vector<int> res_;

 //     void __inorderTraversal(TreeNode* node) {
 //         if (node == nullptr)
 //             return;


 //         __inorderTraversal(node->left);
 //         res_.push_back(node->val);
 //         __inorderTraversal(node->right);

 //         return;

 //     }
 // };


 // class Solution {
 // public:
 //     vector<int> inorderTraversal(TreeNode* root) {
 //         if (root == nullptr)
 //             return {};
 //         stack<TreeNode*> stc;
 //         vector<int> res;
 //         TreeNode* cur = root;

 //         while (cur != nullptr || !stc.empty()) {
 //             while (cur != nullptr) {
 //                 stc.push(cur);
 //                 cur = cur->left;
 //             }
 //             cur = stc.top();
 //             stc.pop();
 //             res.push_back(cur->val);

 //             cur = cur->right;
 //         }

 //         return res;
 //     }

 // };

 // 不使用额外空间的迭代，Morris 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr)
            return {};
        TreeNode* node = root;
        TreeNode* pre = nullptr;
        vector<int> res;
        while (node != nullptr) {
            if (node->left != nullptr) {
                pre = node->left;
                while (pre->right != nullptr && pre->right != node)
                    pre = pre->right;
                if (pre->right == nullptr) {
                    pre->right = node;
                    node = node->left;
                }
                else {
                    pre->right = nullptr;
                    res.push_back(node->val);
                    node = node->right;
                }
            }
            else {
                res.push_back(node->val);
                node = node->right;
            }
        }
        return res;

    }

};