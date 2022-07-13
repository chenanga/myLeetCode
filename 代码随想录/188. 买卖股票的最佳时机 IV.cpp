#include <iostream>
#include <vector>

using namespace std;


/*
         0没有操作
         1第一次买入
         2第一次卖出
         3第二次买入
         4第二次卖出
         ...

         奇数买入，偶数卖出
         dp[i][j]表示第i天状态j所剩最大现金。
         0 <= j <= 2 * k
*/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if (len <= 1 || k == 0) return 0;

        vector<vector<int>> dp(len, vector<int>(2 * k + 1, 0));

        // 初始化
        for (int j = 0; j <= 2 * k; ++j) {
            if (j % 2 == 1)
                dp[0][j] = -prices[0];
        }

        for (int i = 1; i < len; ++i) {
            for (int j = 0; j <= 2 * k; ++j) {
                if (j == 0)
                    dp[i][j] = dp[i - 1][j];
                else if (j % 2 == 1)  // 当前天买入
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
                else  // j % 2 == 0     当前天卖出
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i]);
            }
        }

        // int res = 0;
        // for (int j = 0; j <= 2 * k; ++ j)
        //     res = max(res, dp[len - 1][j]);
        // return res;

        // 最后一次卖出一定是最大的
        return dp[len - 1][2 * k];
    }
};

int main() {

	system("pause");
	return 0;
}