#include <iostream>
#include <vector>

using namespace std;

// 01�����Ķ���ά��
/*
ÿ������������ά�ȣ�һ����0��������һ����1�����������о�������ļ�ֵ

*/
// class Solution {
// public:
//     int findMaxForm(vector<string>& strs, int m, int n) {
//         vector<vector<int>> record(strs.size(), vector<int>(2, 0));
//         // record[i][0] ��i���ַ�����0������
//         for (int i = 0; i < strs.size(); ++ i) {
//             record[i][0] = calculateNum(strs[i]);
//             record[i][1] = strs[i].size() - record[i][0];
//         }
//         // �����i��0��j��1��strs������Ӽ��ĳ���Ϊdp[i][j]��
//         vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
//         for (int i = 0; i < strs.size(); ++ i) {
//             for (int j = m; j >= record[i][0]; -- j) {
//                 for (int k = n; k >= record[i][1]; -- k) {

//                     dp[j][k] = max(dp[j][k], dp[j - record[i][0]][k - record[i][1]] + 1);
//                 }
//             }
//         }
//         return dp[m][n];

//     }
// private:
//     int calculateNum(const string & str) {
//         // ͳ���ַ�����0������������
//         int res = 0;
//         for (char ch : str)
//             if (ch == '0')
//                 res ++;

//         return res;
//     }
// };

// ���ٿռ�ʹ��

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        // �����i��0��j��1��strs������Ӽ��ĳ���Ϊdp[i][j]��
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < strs.size(); ++i) {
            int zeros = calculateNum(strs[i]);
            int ones = strs[i].size() - zeros;

            for (int j = m; j >= zeros; --j) {
                for (int k = n; k >= ones; --k) {
                    dp[j][k] = max(dp[j][k], dp[j - zeros][k - ones] + 1);
                }
            }
        }
        return dp[m][n];

    }
private:
    int calculateNum(const string& str) {
        // ͳ���ַ�����0������������
        int res = 0;
        for (char ch : str)
            if (ch == '0')
                res++;

        return res;
    }
};

int main() {

	system("pause");
	return 0;
}