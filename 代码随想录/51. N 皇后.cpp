#include <iostream>
#include <vector>

using namespace std;

// 打印版本
// class Solution {
// public:
//     vector<vector<string>> solveNQueens(int n) {
//         row = vector<bool>(n, false);
//         column = vector<bool>(n, false);
//         diagonal1 = vector<bool>(2 * (n - 1) + 1, false);
//         diagonal2 = vector<bool>(2 * (n - 1) + 1, false);
//         vector<string> path;
//         cout << " start ----" << endl;
//         __solveNQueens(path, n, 0);
//         return result;
//     }
// private:
//     vector<vector<string>> result;

//     // 确保同一行、同一列、同一斜线只有一个
//     vector<bool> row;  // 行
//     vector<bool> column;  // 列

//     // 还有斜线，，每个方向的斜线有2(n-1) + 1条，
//     vector<bool> diagonal1;  // 左上到右下   （横纵坐标相加，可以知道是处于第几条线）
//     vector<bool> diagonal2;  // 左下到右上    （横坐标减纵坐标 + （n - 1）） 

//     // start：已经放置了几个皇后, 这里选择一行一行的放置
//     void __solveNQueens(vector<string>& path, int n, int start) {
//         cout << "放置皇后" << start << " :   "  ;
//         if (start >= n) {
//             cout << "get a res : " ;
//             for (string pa : path)
//                 cout << pa << ", ";
//             cout << " , return" << endl;
//             result.push_back(path);
//             return;
//         }

//         for (int i = start; i < n; ++ i) {
//             string str = "";
//             for (int j = 0; j < n; ++ j) {
//                 if (row[i] || column[j] || diagonal1[i + j] || diagonal2[i - j + n - 1])
//                     continue;
//                 cout << "皇后" << start << "的位置 = (" << i << ", " << j << ") " << endl;
//                 path.push_back(generate(n, j));
//                 row[i] = true;
//                 column[j] = true;
//                 diagonal1[i + j] = true;
//                 diagonal2[i - j + n - 1] = true;
//                 __solveNQueens(path, n, start + 1);
//                 row[i] = false;
//                 column[j] = false;
//                 diagonal1[i + j] = false;
//                 diagonal2[i - j + n - 1] = false;
//                 path.pop_back();               

//             }
//         }
//         return;

//     }


//     string generate(int n, int index) {
//         string str;
//         for (int i = 0; i < n; ++ i) {
//             if (index == i)
//                 str.push_back('Q');
//             else
//                 str.push_back('.');
//         }
//         return str;
//     }

// };

// // 超时
// class Solution {
// public:
//     vector<vector<string>> solveNQueens(int n) {
//         row = vector<bool>(n, false);
//         column = vector<bool>(n, false);
//         diagonal1 = vector<bool>(2 * (n - 1) + 1, false);
//         diagonal2 = vector<bool>(2 * (n - 1) + 1, false);
//         vector<string> path;
//         __solveNQueens(path, n, 0);
//         return result;
//     }
// private:
//     vector<vector<string>> result;

//     // 确保同一行、同一列、同一斜线只有一个
//     vector<bool> row;  // 行
//     vector<bool> column;  // 列

//     // 还有斜线，，每个方向的斜线有2(n-1) + 1条，
//     vector<bool> diagonal1;  // 左上到右下   （横纵坐标相加，可以知道是处于第几条线）
//     vector<bool> diagonal2;  // 左下到右上    （横坐标减纵坐标 + （n - 1）） 

//     // start：已经放置了几个皇后, 这里选择一行一行的放置
//     void __solveNQueens(vector<string>& path, int n, int start) {
//         if (start >= n) {
//             result.push_back(path);
//             return;
//         }

//         for (int i = start; i < n; ++ i) {
//             string str = "";
//             for (int j = 0; j < n; ++ j) {
//                 if (row[i] || column[j] || diagonal1[i + j] || diagonal2[i - j + n - 1])
//                     continue;
//                 path.push_back(generate(n, j));
//                 row[i] = true;
//                 column[j] = true;
//                 diagonal1[i + j] = true;
//                 diagonal2[i - j + n - 1] = true;
//                 __solveNQueens(path, n, start + 1);
//                 row[i] = false;
//                 column[j] = false;
//                 diagonal1[i + j] = false;
//                 diagonal2[i - j + n - 1] = false;
//                 path.pop_back();               

//             }
//         }
//         return;

//     }


//     string generate(int n, int index) {
//         string str;
//         for (int i = 0; i < n; ++ i) {
//             if (index == i)
//                 str.push_back('Q');
//             else
//                 str.push_back('.');
//         }
//         return str;
//     }

// };

// 可以去掉一个行数组，不需要两层for循环，一层即可，
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {

        column = vector<bool>(n, false);
        diagonal1 = vector<bool>(2 * (n - 1) + 1, false);
        diagonal2 = vector<bool>(2 * (n - 1) + 1, false);
        vector<string> path;
        __solveNQueens(path, n, 0);
        return result;
    }
private:
    vector<vector<string>> result;

    // 确保同一行、同一列、同一斜线只有一个
    vector<bool> column;  // 列

    // 还有斜线，，每个方向的斜线有2(n-1) + 1条，
    vector<bool> diagonal1;  // 左上到右下   （横纵坐标相加，可以知道是处于第几条线）
    vector<bool> diagonal2;  // 左下到右上    （横坐标减纵坐标 + （n - 1）） 

    // start：已经放置了几个皇后, 这里选择一行一行的放置
    // 确定第strat层的皇后的位置
    void __solveNQueens(vector<string>& path, int n, int start) {
        if (start >= n) {
            result.push_back(path);
            return;
        }


        int i = start;
        for (int j = 0; j < n; ++j) {
            if (column[j] || diagonal1[i + j] || diagonal2[i - j + n - 1])
                continue;
            path.push_back(generate(n, j));
            column[j] = true;
            diagonal1[i + j] = true;
            diagonal2[i - j + n - 1] = true;
            __solveNQueens(path, n, start + 1);
            column[j] = false;
            diagonal1[i + j] = false;
            diagonal2[i - j + n - 1] = false;
            path.pop_back();

        }

        return;

    }


    string generate(int n, int index) {
        string str(n, '.');
        str[index] = 'Q';
        return str;
    }

};

int main() {

	system("pause");
	return 0;
}