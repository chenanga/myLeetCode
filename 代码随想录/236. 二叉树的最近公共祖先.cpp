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

/*

*/

// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
//     {
// //����rootΪ���ڵ�����У�Ѱ��p��q������������ȣ����� ���ؿ�
//         //���У�3�����
//         //1��p��q�ֱ�λ��root����������
//         //2��pΪroot��qΪ��������
//         //3��qΪroot��pΪ��������
//         if (root == nullptr || root == q || root == p) return root;
//         TreeNode* left =  lowestCommonAncestor(root->left, p, q);
//         TreeNode* right = lowestCommonAncestor(root->right, p, q);
//         if (left == nullptr && right == nullptr)
//             return nullptr;
//         else if (left == nullptr)
//             return right;
//         else if (right == nullptr)
//             return left;

//         return root;
//     }
// };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == q || root == p) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left == nullptr)
            return right;

        else if (right == nullptr)
            return left;

        return root;
    }
};