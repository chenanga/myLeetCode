#include "general.h"

// //����һȦ����������Ҫ��ÿ�����ߣ�����������ô����ÿ��һ���߶�Ҫ���һ�µ�����ҿ���
// class Solution {
// public:
//     vector<vector<int>> generateMatrix(int n) {

//         //��ʼ��ʱ��ֱ�Ӱ�ȫ����Ϊn^2,������nΪ����ʱ�� �м���ľͲ��ò���
//         vector<vector<int>> res (n, vector<int>(n, n * n));
//         int num = 1;

//         //ѭ�����⵽�ڵĲ���
//         for (int i = 0; i < n / 2; ++ i) {

//             //������
//             for (int j = i; j < n - i - 1; ++ j) {
//                 res[i][j] = num;
//                 ++ num;
//             }

//             //���ϵ���
//             for (int j = i; j < n - i - 1; ++ j ) {
//                 res[j][n - i - 1] = num;
//                 ++ num;
//             }

//             //���ҵ���
//             for (int j = n - i - 1; j >= i + 1; -- j) {
//                 res[n - i - 1][j] = num;
//                 ++ num;
//             }

//             //���µ���
//             for (int j = n - i - 1; j >= i + 1; -- j) {
//                 res[j][i] = num;
//                 ++ num;
//             }

//         }
//         return res;
//     }
// };

//����һȦ����������Ҫ��ÿ�����ߣ�����������ô����ÿ��һ���߶�Ҫ���һ�µ�����ҿ���
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> res(n, vector<int>(n, 0));
        int round = n / 2, num = 1;
        for (int i = 0; i < round; ++i) {
            // ���ϱ�
            for (int j = i; j < n - i - 1; ++j) {
                res[i][j] = num;
                ++num;
            }

            // ���ұ�
            for (int j = i; j < n - i - 1; ++j) {
                res[j][n - i - 1] = num;
                ++num;
            }

            // ��
            for (int j = n - i - 1; j > i; --j) {
                res[n - i - 1][j] = num;
                ++num;
            }

            // ��
            for (int j = n - i - 1; j > i; --j) {
                res[j][i] = num;
                ++num;
            }

        }
        // Ҳ���Գ�ʼ��ʱ��ֱ�Ӱ�ȫ����Ϊn^2,������nΪ����ʱ�� �м���ľͲ��ò���
        if (n % 2 == 1)
            res[n / 2][n / 2] = num;
        return res;
    }
};