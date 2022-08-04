#include "general.h"

// //这里一圈下来，我们要画每四条边，这四条边怎么画，每画一条边都要坚持一致的左闭右开，
// class Solution {
// public:
//     vector<vector<int>> generateMatrix(int n) {

//         //初始化时候直接把全部填为n^2,这样当n为奇数时候 中间的心就不用补了
//         vector<vector<int>> res (n, vector<int>(n, n * n));
//         int num = 1;

//         //循环从外到内的层数
//         for (int i = 0; i < n / 2; ++ i) {

//             //从左到右
//             for (int j = i; j < n - i - 1; ++ j) {
//                 res[i][j] = num;
//                 ++ num;
//             }

//             //从上到下
//             for (int j = i; j < n - i - 1; ++ j ) {
//                 res[j][n - i - 1] = num;
//                 ++ num;
//             }

//             //从右到左
//             for (int j = n - i - 1; j >= i + 1; -- j) {
//                 res[n - i - 1][j] = num;
//                 ++ num;
//             }

//             //从下到上
//             for (int j = n - i - 1; j >= i + 1; -- j) {
//                 res[j][i] = num;
//                 ++ num;
//             }

//         }
//         return res;
//     }
// };

//这里一圈下来，我们要画每四条边，这四条边怎么画，每画一条边都要坚持一致的左闭右开，
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> res(n, vector<int>(n, 0));
        int round = n / 2, num = 1;
        for (int i = 0; i < round; ++i) {
            // 画上边
            for (int j = i; j < n - i - 1; ++j) {
                res[i][j] = num;
                ++num;
            }

            // 画右边
            for (int j = i; j < n - i - 1; ++j) {
                res[j][n - i - 1] = num;
                ++num;
            }

            // 下
            for (int j = n - i - 1; j > i; --j) {
                res[n - i - 1][j] = num;
                ++num;
            }

            // 左
            for (int j = n - i - 1; j > i; --j) {
                res[j][i] = num;
                ++num;
            }

        }
        // 也可以初始化时候直接把全部填为n^2,这样当n为奇数时候 中间的心就不用补了
        if (n % 2 == 1)
            res[n / 2][n / 2] = num;
        return res;
    }
};