#include <iostream>
#include <vector>

using namespace std;

// ��ӡ�汾
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

//     // ȷ��ͬһ�С�ͬһ�С�ͬһб��ֻ��һ��
//     vector<bool> row;  // ��
//     vector<bool> column;  // ��

//     // ����б�ߣ���ÿ�������б����2(n-1) + 1����
//     vector<bool> diagonal1;  // ���ϵ�����   ������������ӣ�����֪���Ǵ��ڵڼ����ߣ�
//     vector<bool> diagonal2;  // ���µ�����    ��������������� + ��n - 1���� 

//     // start���Ѿ������˼����ʺ�, ����ѡ��һ��һ�еķ���
//     void __solveNQueens(vector<string>& path, int n, int start) {
//         cout << "���ûʺ�" << start << " :   "  ;
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
//                 cout << "�ʺ�" << start << "��λ�� = (" << i << ", " << j << ") " << endl;
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

// // ��ʱ
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

//     // ȷ��ͬһ�С�ͬһ�С�ͬһб��ֻ��һ��
//     vector<bool> row;  // ��
//     vector<bool> column;  // ��

//     // ����б�ߣ���ÿ�������б����2(n-1) + 1����
//     vector<bool> diagonal1;  // ���ϵ�����   ������������ӣ�����֪���Ǵ��ڵڼ����ߣ�
//     vector<bool> diagonal2;  // ���µ�����    ��������������� + ��n - 1���� 

//     // start���Ѿ������˼����ʺ�, ����ѡ��һ��һ�еķ���
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

// ����ȥ��һ�������飬����Ҫ����forѭ����һ�㼴�ɣ�
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

    // ȷ��ͬһ�С�ͬһ�С�ͬһб��ֻ��һ��
    vector<bool> column;  // ��

    // ����б�ߣ���ÿ�������б����2(n-1) + 1����
    vector<bool> diagonal1;  // ���ϵ�����   ������������ӣ�����֪���Ǵ��ڵڼ����ߣ�
    vector<bool> diagonal2;  // ���µ�����    ��������������� + ��n - 1���� 

    // start���Ѿ������˼����ʺ�, ����ѡ��һ��һ�еķ���
    // ȷ����strat��Ļʺ��λ��
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