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
 //     TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
 //         int len = nums.size();
 //         record = vector<vector<int>>(len, vector<int>(len, 0));
 //         for (int i = 0; i < len; ++ i)
 //             record[i][i] = i;

 //         for (int i = 0; i < len; ++ i) {
 //             for (int j = i + 1; j < len; ++ j) {
 //                 if (nums[j] > nums[record[i][j - 1]])
 //                     record[i][j] = j;
 //                 else
 //                     record[i][j] = record[i][j - 1];
 //             }
 //         }
 //         return __construct(nums, 0, len - 1);
 //     }

 // private:
 //     vector<vector<int>> record; // record[i][j] 为 nums[i, j]中最大值所在的索引
 //     // 在nums[left, right] 找到最大值对应的索引，
 //     TreeNode* __construct(vector<int>& nums, int left, int right) {
 //         if (left > right) return nullptr;
 //         int max_index = record[left][right];
 //         TreeNode* root = new TreeNode(nums[max_index]);
 //         root->left = __construct(nums, left, max_index - 1);
 //         root->right = __construct(nums, max_index + 1, right);
 //         return root;
 //     }
 // };


class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int len = nums.size();
        return __construct(nums, 0, len - 1);
    }

private:
    TreeNode* __construct(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        int max_index = left;

        for (int i = left; i <= right; ++i) {
            if (nums[i] > nums[max_index])
                max_index = i;
        }

        TreeNode* root = new TreeNode(nums[max_index]);
        root->left = __construct(nums, left, max_index - 1);
        root->right = __construct(nums, max_index + 1, right);
        return root;
    }
};