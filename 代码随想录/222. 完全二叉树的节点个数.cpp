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
 //     int countNodes(TreeNode* root) {
 //         if (root == nullptr) return 0;
 //         return 1 + countNodes(root->left) + countNodes(root->right);
 //     }

 // };

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int depth = getLeftDepth(root);
        if (depth == 1) return 1;
        // ���һ��ķ�ΧΪ2^(depth - 1) --->  2^depth - 1
        int left = 1 << (depth - 1), right = (1 << depth) - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isExits(root, mid, depth)) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return right;
    }
private:
    int getLeftDepth(TreeNode* node) {
        if (node == nullptr) return 0;
        return 1 + getLeftDepth(node->left);
    }
    bool isExits(TreeNode* root, int mid, int depth) {
        int bits = 1 << (depth - 2);
        TreeNode* node = root;
        while (node != nullptr && bits > 0) {
            if ((bits & mid) == 0) {   // 0010   ��һ��01xx �룬��ô�൱���Ǻ������λ��1��Ȼ�󿴴θ�λ�������Ƿ�Ϊ0�����Ϊ0������������������
                node = node->left;
            }
            else {
                node = node->right;
            }
            bits >>= 1;
        }
        return node != nullptr;
    }
};