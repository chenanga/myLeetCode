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
    // ��ǰ�ڵ�ѡ��͵����ǰ�ڵ���͵�������Ǯ�� = ������͵�������Ǯ + �Һ�����͵������Ǯ
    // ע��������͵�������Ǯ: max(����ѡ��͵ʱ��Ǯ������ѡ��͵ʱ��Ǯ)
    // ��ǰ�ڵ�ѡ��͵����ǰ�ڵ���͵�������Ǯ�� = ����ѡ���Լ���͵ʱ�ܵõ���Ǯ + �Һ���ѡ��͵ʱ�ܵõ���Ǯ + ��ǰ�ڵ��Ǯ��
private:
    // ��vector���ɽṹ�壬������
    struct sumrob {
        int select;
        int noselect;
    };
    sumrob __rob(TreeNode* root) {
        if (root == nullptr)
            return { 0, 0 };

        sumrob left = __rob(root->left);
        sumrob right = __rob(root->right);
        // o Ϊ͵�Լ�ʱ������Ǯ��1Ϊ��͸�Լ�ʱ���

        // ��ǰ�ڵ�ѡ��͵����ǰ�ڵ���͵�������Ǯ�� = ����ѡ���Լ���͵ʱ�ܵõ���Ǯ + �Һ���ѡ��͵ʱ�ܵõ���Ǯ + ��ǰ�ڵ��Ǯ��
        int res1 = root->val + left.noselect + right.noselect;

        // ��ǰ�ڵ�ѡ��͵����ǰ�ڵ���͵�������Ǯ�� = ������͵�������Ǯ + �Һ�����͵������Ǯ
        int res2 = max(left.select, left.noselect) + max(right.select, right.noselect);
        return { res1, res2 };
    }
};

int main() {

	system("pause");
	return 0;
}