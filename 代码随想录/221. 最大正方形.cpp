#include<iostream>
#include<vector>

using namespace std;

// //��̬�滮
// //������ dp(i,j) ��ʾ�� (i,j) Ϊ���½ǣ���ֻ���� 1 �������εı߳����ֵ��
// class Solution {
// public:
//     int maximalSquare(vector<vector<char>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         int res = 0;

//         // dp(i,j) ��ʾ�� (i,j) Ϊ���½ǣ���ֻ���� 1 �������εı߳����ֵ��
//         vector<vector<int>> dp(m, vector<int>(n, 0));

//         // ��ʼ��, ��ʼ��һ�к͵�һ�У�������ֱֵ�����
//         for (int i = 0; i < m; ++ i) 
//             if (matrix[i][0] == '1') {
//                 dp[i][0] = 1;
//                 if (dp[i][0] > res)
//                     res = dp[i][0];
//             }
//         for (int i = 0; i < n; ++ i)
//             if (matrix[0][i] == '1') {
//                 dp[0][i] = 1;
//                 if (dp[0][i] > res)
//                     res = dp[0][i];                
//             }


//         for (int i = 1; i < m; ++ i) {
//             for ( int j = 1; j < n; ++ j) {
//                 if (matrix[i][j] == '1') {
//                     dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
//                     if (dp[i][j] > res)
//                         res = dp[i][j];
//                 }
//             }
//         }

//         return res * res;
//     }
// };


// �ٷ��򻯰汾�������ʼ��

//��̬�滮
//������ dp(i,j) ��ʾ�� (i,j) Ϊ���½ǣ���ֻ���� 1 �������εı߳����ֵ��
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;

        // dp(i,j) ��ʾ�� (i,j) Ϊ���½ǣ���ֻ���� 1 �������εı߳����ֵ��
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;

                    if (dp[i][j] > res)
                        res = dp[i][j];
                }

        return res * res;
    }
};

int main() {

	system("pause");
	return 0;
}