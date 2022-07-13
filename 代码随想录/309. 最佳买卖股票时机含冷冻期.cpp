#include <iostream>
#include <vector>

using namespace std;

/*
当前有4状态
    0持有股票: 昨天之前持有，或者今天买入（有两种情况，昨天是冷冻期或昨天是卖出状态）

    未持有股票
        1之前就卖出了，一直没操作，度过了冷冻期：昨天就是这个状态，或者昨天是冷冻期
        2今天卖出的， 昨天持有，今天卖出

    3冷冻期
    dp[i][0] = max(dp[i-1][0], max(dp[i-1][1] - prices[i], dp[i-1][3] - prices[i]))
    dp[i][1] = max(dp[i-1][1], dp[i-1][3])  // 可以从冷冻期变过来
    dp[i][2] = dp[i-1][0] + prices[i]
    dp[i][3] = dp[i-1][2]

*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len <= 1) return 0;
        vector<vector<int>> dp(len, vector<int>(4, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;
        dp[0][3] = 0;

        for (int i = 1; i < len; ++i) {
            for (int j = 0; j < 4; ++j) {
                // 注意这里状态0的前置状态有多个可能，需要考虑全面
                dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1] - prices[i], dp[i - 1][3] - prices[i]));
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
                dp[i][2] = dp[i - 1][0] + prices[i];
                dp[i][3] = dp[i - 1][2];
            }
        }

        return max(dp[len - 1][1], max(dp[len - 1][2], dp[len - 1][3]));

    }
};

int main() {

	system("pause");
	return 0;
}