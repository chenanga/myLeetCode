#include <iostream>
#include <vector>

using namespace std;

// // 动态规划
// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int len = cost.size();
//         vector<int> dp(len + 1, 0);  // 定义dp[i] 为从楼下到第i个台阶的最低费用
//         /*
//         dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2])
//         */
//         dp[0] = 0, dp[1] = 0; // 由于可以从0或者1开始趴，所有这两个初始化为0

//         for (int i = 2; i <= len; ++ i) {
//             dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
//         }
//         return dp[len];
//     }
// };

// 动态规划, 空间优化
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        vector<int> dp(3, 0);  // 定义dp[i] 为从楼下到第i个台阶的最低费用
        /*
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2])
        */
        dp[0] = 0, dp[1] = 0; // 由于可以从0或者1开始趴，所有这两个初始化为0

        for (int i = 2; i <= len; ++i) {
            dp[2] = min(dp[1] + cost[i - 1], dp[0] + cost[i - 2]);
            dp[0] = dp[1];
            dp[1] = dp[2];
        }
        return dp[2];
    }
};



int main() {

	system("pause");
	return 0;
}