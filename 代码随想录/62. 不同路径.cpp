#include <iostream>
#include <vector>

using namespace std;

// ��̬�滮
// class Solution {
// public:
//     int uniquePaths(int m, int n) {

//         vector<vector<int>> dp(m, vector<int>(n, 1));  // dp[i][j]Ϊstart��i��jλ�õ���·������
//         // ��ʼ��   ��һ�к͵�һ�ж���1����Ϊ������ֻ�����һ�����

//         for (int i = 1; i < m; ++ i) {
//             for (int j = 1; j < n; ++ j) {
//                 // ����߻����ϱߵ���ǰλ��
//                 dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//             }
//         }
//         return dp[m - 1][n - 1];
//     }
// };


// �ռ��Ż�
class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<int> dp(n, 1);  // dp[i]Ϊstart��iλ�õ���·������
        // ��ʼ��   ��һ�к͵�һ�ж���1����Ϊ������ֻ�����һ�����
        // ����ʹ��һ����������Ϊû����֮ǰdp[i]����һ�еģ���dp[i-1]�ǵ�ǰ�е�
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                // ����߻����ϱߵ���ǰλ��
                dp[j] = dp[j] + dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};

int main() {

	system("pause");
	return 0;
}