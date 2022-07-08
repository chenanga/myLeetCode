#include <iostream>
#include <vector>

using namespace std;

/*
n 是背包容量
完全平方数是物品，每个物品数量无线。
*/
class Solution {
public:
    int numSquares(int n) {
        int maxNum = sqrt(n);
        // 物品为1... maxNum的平方
        vector<int> dp(n + 1, 10001);
        // dp[i] 位i的完全平方数的最少数量
        // dp[i] = min(dp[i-1] + 1, dp[i - 4] + 1, dp[i - maxnum*maxnum] + 1)
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= maxNum; ++j) {
                if (i >= j * j)
                    dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};

int main() {

	system("pause");
	return 0;
}