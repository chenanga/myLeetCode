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

/*
第一种情况：没找到删除的节点，遍历到空节点直接返回了
找到删除的节点
第二种情况：左右孩子都为空（叶子节点），直接删除节点， 返回NULL为根节点
第三种情况：删除节点的左孩子为空，右孩子不为空，删除节点，右孩子补位，返回右孩子为根节点
第四种情况：删除节点的右孩子为空，左孩子不为空，删除节点，左孩子补位，返回左孩子为根节点
第五种情况：左右孩子节点都不为空，则将删除节点的左子树头结点（左孩子）放到删除节点的右子树的最左面节点的左孩子上，返回删除节点右孩子为新的根节点。
*/
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        if (root->val == key) {
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                root = nullptr;
                return nullptr;
            } else if (root->left == nullptr) {
                TreeNode* right = root->right;
                delete root;
                root = nullptr;
                return right;
            } else if (root->right == nullptr) {
                TreeNode* left = root->left;
                delete root;
                root = nullptr;
                return left;
            } else {  // root->left != nullptr && root->rigth != nullptr
                TreeNode* right_left_child = root->right;
                while (right_left_child->left != nullptr)
                    right_left_child = right_left_child->left;
                right_left_child->left = root->left;
                TreeNode* right = root->right;
                delete root;
                root = nullptr;
                return right;
            }
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        } else {  // root->val > key
            root->left = deleteNode(root->left, key);
            return root;
        }
        return root;
    }
};
