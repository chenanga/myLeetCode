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

// //����һȦ����������Ҫ��ÿ�����ߣ�����������ô����ÿ��һ���߶�Ҫ���һ�µ�����ҿ���
// class Solution {
// public:
//     vector<vector<int>> generateMatrix(int n) {

//         vector<vector<int>> res(n ,vector<int>(n, 0));
//         int round = n / 2, num = 1;
//         for (int i = 0; i < round; ++ i) {
//             // ���ϱ�
//             for (int j = i; j < n - i - 1; ++ j) {
//                 res[i][j] = num;
//                 ++ num;
//             }

//             // ���ұ�
//             for (int j = i; j < n - i - 1; ++ j) {
//                 res[j][n - i - 1] = num;
//                 ++ num;
//             }

//             // ��
//             for (int j = n - i - 1; j > i; -- j) {
//                 res[n - i - 1][j] = num;
//                 ++ num;
//             }

//             // ��
//             for (int j = n - i - 1; j > i; -- j) {
//                 res[j][i] = num;
//                 ++ num;
//             }

//         }
//         // Ҳ���Գ�ʼ��ʱ��ֱ�Ӱ�ȫ����Ϊn^2,������nΪ����ʱ�� �м���ľͲ��ò���
//         if (n % 2 == 1)
//             res[n / 2][n / 2] = num ;
//         return res;
//     }
// };


// ʵ��һЩwhileֱ����䣬���������߽����Ԫ�أ���ת��
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> res(n, vector<int>(n, 0));
        int curNum = 1;
        int maxNum = n * n;
        vector<vector<int>> direction = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
        int directIndex = 0;
        int x = 0, y = -1;
        while (curNum <= maxNum) {
            int nextx = x + direction[directIndex][0];
            int nexty = y + direction[directIndex][1];
            if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= n || res[nextx][nexty] != 0)
                directIndex = (directIndex + 1) % 4;

            x += direction[directIndex][0];
            y += direction[directIndex][1];
            res[x][y] = curNum;
            curNum++;

        }
        return res;

    }
};