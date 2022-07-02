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
 �ֲ����ţ���Ҷ�ӽڵ�ĸ��ڵ㰲����ͷ����������ͷ���٣��������ţ�ȫ������ͷ�����������٣�
 ÿ���ڵ��״̬���������
 0���ýڵ��޸���
 1�����ڵ�������ͷ
 2�����ڵ��и���

 */
 // �ݹ���
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
 //             // ���ҽڵ�������һ��û�и���,�ýڵ�����һ������ͷ
 //             result ++;
 //             return 1;
 //         }

 //         if (left == 2 && right == 2)  // ���ҽڵ㶼�и���
 //             return 0;

 //         if (left == 1 || right == 1)  // ���ҽڵ�������һ������ͷ
 //             return 2;

 //         // ��� return -1 �߼������ߵ����
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

        if (left == 2 && right == 2)  // ���ҽڵ㶼�и���
            return 0;

        else if (left == 0 || right == 0) {
            // ���ҽڵ�������һ��û�и���,�ýڵ�����һ������ͷ
            result++;
            return 1;
        }

        else // (left == 1 || right == 1)  // ���ҽڵ�������һ������ͷ
            return 2;

    }
};

int main() {

	system("pause");
	return 0;
}