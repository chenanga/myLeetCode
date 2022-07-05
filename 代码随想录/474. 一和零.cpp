#include <iostream>
#include <vector>

using namespace std;

// 01背包的多重维度
/*
每个物体有两个维度，一个是0的数量，一个是1的数量，还有就是物体的价值

*/
// class Solution {
// public:
//     int findMaxForm(vector<string>& strs, int m, int n) {
//         vector<vector<int>> record(strs.size(), vector<int>(2, 0));
//         // record[i][0] 第i个字符串中0的数量
//         for (int i = 0; i < strs.size(); ++ i) {
//             record[i][0] = calculateNum(strs[i]);
//             record[i][1] = strs[i].size() - record[i][0];
//         }
//         // 最多有i个0和j个1的strs的最大子集的长度为dp[i][j]。
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
//         // 统计字符串中0的数量并返回
//         int res = 0;
//         for (char ch : str)
//             if (ch == '0')
//                 res ++;

//         return res;
//     }
// };

// 减少空间使用

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        // 最多有i个0和j个1的strs的最大子集的长度为dp[i][j]。
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
        // 统计字符串中0的数量并返回
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