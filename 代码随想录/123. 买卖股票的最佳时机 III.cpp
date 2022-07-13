#include <iostream>
#include <vector>

using namespace std;

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         // 由于最多完成两笔交易
//         // 一天一共有五种状态
//         /*
//         没有操作
//         第一次买入
//         第一次卖出
//         第二次买入
//         第二次卖出
//         dp[i][j]中 i表示第i天，j为 [0 - 4] 五个状态，dp[i][j]表示第i天状态j所剩最大现金。
//         dp[i][1]，表示的是第i天，是第一次买入股票的状态

//         dp[i][0] = dp[i-1][0];
//         dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])
//         dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i])
//         dp[i][3] = max(dp[i-1][3], dp[i-1][2] - prices[i])
//         dp[i][4] = max(dp[i-1][4], dp[i-1][3] + prices[i])
//         */
//         int len = prices.size();
//         vector<vector<int>> dp(len, vector<int>(5, 0));
//         dp[0][0] = 0;
//         dp[0][1] = -prices[0];
//         dp[0][2] = 0;
//         dp[0][3] = -prices[0];
//         dp[0][4] = 0;

//         for (int i = 1; i < len; ++ i) {
//             dp[i][0] = dp[i-1][0];
//             dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
//             dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i]);
//             dp[i][3] = max(dp[i-1][3], dp[i-1][2] - prices[i]);
//             dp[i][4] = max(dp[i-1][4], dp[i-1][3] + prices[i]);          
//         }
//         return max(dp[len - 1][0], max(dp[len - 1][2], dp[len - 1][4]));

//     }
// };


// 空间优化
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int len = prices.size();
        vector<int> dp(5, 0);
        dp[0] = 0;
        dp[1] = -prices[0];
        dp[2] = 0;
        dp[3] = -prices[0];
        dp[4] = 0;

        for (int i = 1; i < len; ++i) {
            // dp[2]利用的是当天的dp[1]。 但结果也是对的。
            /*
            dp[1] = max(dp[1], dp[0] - prices[i]); 如果dp[1]取dp[1]，即保持买入股票的状态，
            那么 dp[2] = max(dp[2], dp[1] + prices[i]);中dp[1] + prices[i] 就是今天卖出。
            如果dp[1]取dp[0] - prices[i]，今天买入股票，那么dp[2] = max(dp[2], dp[1] + prices[i]);
            中的dp[1] + prices[i]相当于是尽在再卖出股票，一买一卖收益为0，对所得现金没有影响。
            相当于今天买入股票又卖出股票，等于没有操作，保持昨天卖出股票的状态了。
            */
            dp[1] = max(dp[1], dp[0] - prices[i]);
            dp[2] = max(dp[2], dp[1] + prices[i]);
            dp[3] = max(dp[3], dp[2] - prices[i]);
            dp[4] = max(dp[4], dp[3] + prices[i]);
        }
        return max(dp[0], max(dp[2], dp[4]));

    }
};

int main() {

	system("pause");
	return 0;
}