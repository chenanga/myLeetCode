#include <iostream>
#include <vector>

using namespace std;

// 贪心
// class Solution {
// public:
//     int maxProfit(vector<int>& prices, int fee) {
//         int result = 0;
//         int minPrice = prices[0];
//         for (int i = 0; i < prices.size(); ++ i) {
//             // 更新最低价格
//             if (prices[i] < minPrice) minPrice = prices[i];

//             // if (prices[i] - minPrice <= fee)  // 可以省略
//             //     continue; 
//             if (prices[i] > minPrice + fee) {
//                 result += (prices[i] - minPrice - fee);
//                 minPrice = prices[i] - fee;  // 不是真的卖出
//                 /*
//                 我们此时卖出股票可能并不是全局最优的（例如下一天股票价格继续上升），
//                 因此我们可以提供一个反悔操作，看成当前手上拥有一支买入价格为 prices[i] 的股票
//                 如果下一天股票继续上升，那么赚的钱是prices[i+1] - minprices, 此时由于手续费被提前减掉               了，相当于两天合在一起交易的


//                 */
//             }
//         }
//         return result;
//     }
// };

//  动态规划
/*
dp[i][0] 表示第i天持有股票所省最多现金。 dp[i][1] 表示第i天不持有股票所得最多现金

    dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i])
    dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i] - fee)
*/
// class Solution {
// public:
//     int maxProfit(vector<int>& prices, int fee) {
//         int len = prices.size();
//         if (len <= 1) return 0;

//         vector<vector<int>> dp(len, vector<int>(2, 0));
//         dp[0][0] = -prices[0];
//         dp[0][1] = 0;

//         for (int i = 1; i < len; ++ i) {
//             dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i]);
//             dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i] - fee);
//         }
//         // return max(dp[len-1][0], dp[len-1][1]);
//         // 最后一天肯定是不持有股票最多
//         return dp[len-1][1];

//     }
// };

// 动归 空间优化
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int len = prices.size();
        if (len <= 1) return 0;

        vector<int> pre(2, 0);
        vector<int> cur(2, 0);

        pre[0] = -prices[0];
        pre[1] = 0;

        for (int i = 1; i < len; ++i) {
            cur[0] = max(pre[0], pre[1] - prices[i]);
            cur[1] = max(pre[1], pre[0] + prices[i] - fee);
            pre = cur;
        }

        // 最后一天肯定是不持有股票最多
        return cur[1];

    }
};

int main() {

	system("pause");
	return 0;
}