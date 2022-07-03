#include <iostream>
#include <vector>

using namespace std;

// 动态规划
// class Solution {
// public:
//     int uniquePaths(int m, int n) {

//         vector<vector<int>> dp(m, vector<int>(n, 1));  // dp[i][j]为start到i，j位置的总路径数量
//         // 初始化   第一行和第一列都是1，因为机器人只能向右或向下

//         for (int i = 1; i < m; ++ i) {
//             for (int j = 1; j < n; ++ j) {
//                 // 有左边或者上边到当前位置
//                 dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//             }
//         }
//         return dp[m - 1][n - 1];
//     }
// };


// 空间优化
class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<int> dp(n, 1);  // dp[i]为start到i位置的总路径数量
        // 初始化   第一行和第一列都是1，因为机器人只能向右或向下
        // 这里使用一行数组是因为没更新之前dp[i]是上一行的，而dp[i-1]是当前行的
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                // 有左边或者上边到当前位置
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