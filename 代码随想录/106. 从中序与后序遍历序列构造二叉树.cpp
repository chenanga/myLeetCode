#include "general.h"
#include <unordered_map>
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
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); ++i)
            mp[inorder[i]] = i;
        return __buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }

private:
    unordered_map<int, int> mp;
    // inorder[in_left, in_right]   postorder[post_left, post_right]
    TreeNode* __buildTree(vector<int>& inorder, vector<int>& postorder, int in_left, int in_right, int post_left, int post_right) {
        if (in_left > in_right || post_left > post_right) return nullptr;
        TreeNode* root = new TreeNode(postorder[post_right]);
        int mid = mp[postorder[post_right]];

        root->left = __buildTree(inorder, postorder, in_left, mid - 1, post_left, post_left + (mid - in_left) - 1);
        root->right = __buildTree(inorder, postorder, mid + 1, in_right, post_left + (mid - in_left), post_right - 1);
        return root;

    }
};