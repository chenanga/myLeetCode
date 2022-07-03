#include <iostream>
#include <vector>

using namespace std;

// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size(), n = obstacleGrid[0].size();
//         vector<vector<int>> dp(m, vector<int>(n, 1));  // dp[i][j]为start到i，j位置的总路径数量
//         // 初始化   因为机器人只能向右或向下,障碍物格子是0，第1行如果中间有障碍物，则后面全是0
//         dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
//         for (int i = 1; i < m; ++ i) {
//             if (obstacleGrid[i][0] == 1)
//                 dp[i][0] = 0;
//             else
//                 dp[i][0] = dp[i - 1][0];
//         }

//         for (int j = 1; j < n; ++ j) {
//             if (obstacleGrid[0][j] == 1)
//                 dp[0][j] = 0;
//             else
//                 dp[0][j] = dp[0][j - 1];
//         }

//         for (int i = 1; i < m; ++ i) {
//             for (int j = 1; j < n; ++ j) {
//                 if (obstacleGrid[i][j] == 1)
//                     dp[i][j] = 0;
//                 else
//                     dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//             }
//         }
//         return dp[m - 1][n - 1];
//     }
// };

// // 优化代码1
// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size(), n = obstacleGrid[0].size();
//         vector<vector<int>> dp(m, vector<int>(n, 0));  // dp[i][j]为start到i，j位置的总路径数量
//         // 初始化   因为机器人只能向右或向下,障碍物格子是0，第1行如果中间有障碍物，则后面全是0
//         dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
//         for (int i = 1; i < m; ++ i) {
//             if (obstacleGrid[i][0] != 1)
//                 dp[i][0] = dp[i - 1][0];
//         }

//         for (int j = 1; j < n; ++ j) {
//             if (obstacleGrid[0][j] != 1)
//                 dp[0][j] = dp[0][j - 1];
//         }

//         for (int i = 1; i < m; ++ i) {
//             for (int j = 1; j < n; ++ j) {
//                 if (obstacleGrid[i][j] != 1)
//                     dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//             }
//         }
//         return dp[m - 1][n - 1];
//     }
// };

// // 优化代码2
// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size(), n = obstacleGrid[0].size();
//         vector<vector<int>> dp(m, vector<int>(n, 0));  // dp[i][j]为start到i，j位置的总路径数量
//         // 初始化   因为机器人只能向右或向下,障碍物格子是0，第1行如果中间有障碍物，则后面全是0

//         for (int i = 0; i < m && obstacleGrid[i][0] != 1; ++ i)  // 一旦遇到障碍物停止赋值，其后的都是初始值0
//             dp[i][0] = 1;


//         for (int j = 0; j < n && obstacleGrid[0][j] != 1; ++ j) 
//             dp[0][j] = 1;

//         for (int i = 1; i < m; ++ i) {
//             for (int j = 1; j < n; ++ j) {
//                 if (obstacleGrid[i][j] != 1)
//                     dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//             }
//         }
//         return dp[m - 1][n - 1];
//     }
// };


// 优化代码4，空间优化
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> dp(n, 0);  // dp[i]为start到i，j位置的总路径数量
        // 初始化   因为机器人只能向右或向下,障碍物格子是0，第1行如果中间有障碍物，则后面全是0

        // 一旦遇到障碍物停止赋值，其后的都是初始值0  
        for (int j = 0; j < n && obstacleGrid[0][j] != 1; ++j)
            dp[j] = 1;

        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] != 1) {
                    if (j != 0)  // j=0时候继承上一次，
                        dp[j] = dp[j] + dp[j - 1];
                }
                else
                    dp[j] = 0;

            }
        }
        return dp[n - 1];
    }
};

int main() {

	system("pause");
	return 0;
}