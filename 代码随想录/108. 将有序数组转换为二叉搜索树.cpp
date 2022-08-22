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
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return __sortedArrayToBST(nums, 0, nums.size() - 1);
    }

private:
    // nums[left...right] 建立二叉树
    TreeNode* __sortedArrayToBST(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        if (left == right)
            return new TreeNode(
                nums[left]);  //当当前数组范围为1时候，直接返回即可，不需要进去子递归，减少耗时
        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = __sortedArrayToBST(nums, left, mid - 1);
        node->right = __sortedArrayToBST(nums, mid + 1, right);
        return node;
    }
};