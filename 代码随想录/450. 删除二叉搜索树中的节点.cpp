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
��һ�������û�ҵ�ɾ���Ľڵ㣬�������սڵ�ֱ�ӷ�����
�ҵ�ɾ���Ľڵ�
�ڶ�����������Һ��Ӷ�Ϊ�գ�Ҷ�ӽڵ㣩��ֱ��ɾ���ڵ㣬 ����NULLΪ���ڵ�
�����������ɾ���ڵ������Ϊ�գ��Һ��Ӳ�Ϊ�գ�ɾ���ڵ㣬�Һ��Ӳ�λ�������Һ���Ϊ���ڵ�
�����������ɾ���ڵ���Һ���Ϊ�գ����Ӳ�Ϊ�գ�ɾ���ڵ㣬���Ӳ�λ����������Ϊ���ڵ�
��������������Һ��ӽڵ㶼��Ϊ�գ���ɾ���ڵ��������ͷ��㣨���ӣ��ŵ�ɾ���ڵ����������������ڵ�������ϣ�����ɾ���ڵ��Һ���Ϊ�µĸ��ڵ㡣
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
