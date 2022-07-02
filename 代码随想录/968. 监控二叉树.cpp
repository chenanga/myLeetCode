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

 /*
 局部最优：让叶子节点的父节点安摄像头，所用摄像头最少，整体最优：全部摄像头数量所用最少！
 每个节点的状态有三种情况
 0：该节点无覆盖
 1：本节点有摄像头
 2：本节点有覆盖

 */
 // 递归树
 // class Solution {
 // public:
 //     int minCameraCover(TreeNode* root) {
 //         int ret = __minCameraCover(root);
 //         if (ret == 0)
 //             result ++;
 //         return result;
 //     }
 // private:
 //     int result = 0;
 //     int __minCameraCover(TreeNode* node) {
 //         if (node == nullptr)
 //             return 2;

 //         int left = __minCameraCover(node->left);
 //         int right = __minCameraCover(node->right);

 //         if (left == 0 || right == 0) {
 //             // 左右节点至少有一个没有覆盖,该节点新增一个摄像头
 //             result ++;
 //             return 1;
 //         }

 //         if (left == 2 && right == 2)  // 左右节点都有覆盖
 //             return 0;

 //         if (left == 1 || right == 1)  // 左右节点至少有一个摄像头
 //             return 2;

 //         // 这个 return -1 逻辑不会走到这里。
 //         return -1;
 //     }
 // };


class Solution {
public:
    int minCameraCover(TreeNode* root) {
        int ret = __minCameraCover(root);
        if (ret == 0)
            result++;
        return result;
    }
private:
    int result = 0;
    int __minCameraCover(TreeNode* node) {
        if (node == nullptr)
            return 2;

        int left = __minCameraCover(node->left);
        int right = __minCameraCover(node->right);

        if (left == 2 && right == 2)  // 左右节点都有覆盖
            return 0;

        else if (left == 0 || right == 0) {
            // 左右节点至少有一个没有覆盖,该节点新增一个摄像头
            result++;
            return 1;
        }

        else // (left == 1 || right == 1)  // 左右节点至少有一个摄像头
            return 2;

    }
};

int main() {

	system("pause");
	return 0;
}