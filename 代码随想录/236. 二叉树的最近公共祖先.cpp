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
// //在以root为根节点的树中，寻找p，q的最近公共祖先，若无 返回空
//         //若有，3种情况
//         //1、p和q分别位于root的左右两侧
//         //2、p为root，q为左右两侧
//         //3、q为root，p为左右两测
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