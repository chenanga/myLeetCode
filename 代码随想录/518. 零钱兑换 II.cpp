#include <iostream>
#include <vector>

using namespace std;

// // 超时了  14 / 28 个通过测试用例
// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         sort(coins.begin(), coins.end());
//         result = 0;
//         // 最多使用的硬币总数
//         maxCoins = amount / coins[0] + 1;
//         __change(amount, coins, 0, 0, 0);
//         return result;

//     }

// private:
//     int result, maxCoins;
//     void __change(int amount, vector<int>& coins, int count, int sum, int index) {
//         if (count > maxCoins && sum != amount)
//             return;
//         if (sum == amount) {
//             result ++;
//             return;
//         }

//         for (int i = index; i < coins.size(); ++ i) {
//             __change(amount, coins, count + 1, sum + coins[i], i);
//         }
//         return;
//     }
// };


// // 动态规划,时间还是有点长，因为不确定每次用几个当前硬币，所以多了一个循环
// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         int len = coins.size();
//         vector<int> dp(amount + 1, 0);  //dp[i][j]代表coins[0..i]能表示的金额为j的总数量
//         // dp[i][j] = dp[i-1][j] + dp[i - 1][j - coins[i]];
//         // 初始化

//         for (int j = 0; j <= amount; ++ j) {
//             if (j % coins[0] == 0) 
//                 dp[j] = 1;
//         }

//         for (int i = 1; i < len; ++ i) {
//             for (int j = amount; j >= coins[i] ; -- j) {
//                 for (int k = 1; k <= j / coins[i]; ++ k) {
//                     // 使用0个硬币到j/coins[i]个硬币
//                     if (j >= k * coins[i])
//                         dp[j] += dp[j - k * coins[i]];  
//                 }
//             }
//         }
//         return dp[amount];    
//     }
// };

// 动态规划
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int len = coins.size();
        vector<int> dp(amount + 1, 0);  //dp[i][j]代表coins[0..i]能表示的金额为j的总数量
        // dp[j] += dp[j - coins[i]];
        // 初始化

        dp[0] = 1;
        for (int i = 0; i < len; ++i) {
            for (int j = coins[i]; j <= amount; ++j) {
                dp[j] += dp[j - coins[i]];

            }
        }
        return dp[amount];
    }
};

int main() {

	system("pause");
	return 0;
}