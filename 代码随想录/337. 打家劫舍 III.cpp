#include <iostream>
#include <vector>

using namespace std;

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

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
  
};

class Solution {
public:
    int rob(TreeNode* root) {
        if (root == nullptr)
            return 0;
        sumrob res = __rob(root);
        return max(res.select, res.noselect);
    }
    // 当前节点选择不偷：当前节点能偷到的最大钱数 = 左孩子能偷到的最大钱 + 右孩子能偷到最大的钱
    // 注：左孩子能偷到的最大钱: max(左孩子选择不偷时的钱，左孩子选择偷时的钱)
    // 当前节点选择偷：当前节点能偷到的最大钱数 = 左孩子选择自己不偷时能得到的钱 + 右孩子选择不偷时能得到的钱 + 当前节点的钱数
private:
    // 把vector换成结构体，更快了
    struct sumrob {
        int select;
        int noselect;
    };
    sumrob __rob(TreeNode* root) {
        if (root == nullptr)
            return { 0, 0 };

        sumrob left = __rob(root->left);
        sumrob right = __rob(root->right);
        // o 为偷自己时候的最大钱，1为不透自己时候的

        // 当前节点选择偷：当前节点能偷到的最大钱数 = 左孩子选择自己不偷时能得到的钱 + 右孩子选择不偷时能得到的钱 + 当前节点的钱数
        int res1 = root->val + left.noselect + right.noselect;

        // 当前节点选择不偷：当前节点能偷到的最大钱数 = 左孩子能偷到的最大钱 + 右孩子能偷到最大的钱
        int res2 = max(left.select, left.noselect) + max(right.select, right.noselect);
        return { res1, res2 };
    }
};

int main() {

	system("pause");
	return 0;
}