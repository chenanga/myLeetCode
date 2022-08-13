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
 // µÝ¹é
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         __preorderTraversal(root);
//         return res_;
//     }
// private:
//     vector<int> res_;

//     void __preorderTraversal(TreeNode* node) {
//         if (node == nullptr)
//             return;

//         res_.push_back(node->val);
//         __preorderTraversal(node->left);
//         __preorderTraversal(node->right);

//         return;

//     }
// };


// µü´ú
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr)
            return {};
        stack<TreeNode*> stc;
        vector<int> res;
        stc.push(root);

        while (!stc.empty()) {
            TreeNode* temp = stc.top();
            stc.pop();
            res.push_back(temp->val);
            if (temp->right != nullptr)
                stc.push(temp->right);

            if (temp->left != nullptr)
                stc.push(temp->left);

        }

        return res;
    }

};