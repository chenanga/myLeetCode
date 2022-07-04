#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        // 转换为背包问题，
        int sum = 0, len = stones.size();
        for (int i = 0; i < len; ++i)
            sum += stones[i];
        int target = sum / 2;
        vector<int> dp(target + 1, 0);
        // dp[j]表示容量（这里说容量更形象，其实就是重量）为j的背包，最多可以背dp[j]这么重的石头。
        // 初始化为0
        // dp[i] = max(dp[i], dp[i - stones[i]] + stones[i])
        for (int i = 0; i < len; ++i) // 遍历物品
            for (int j = target; j >= stones[i]; --j) { // 遍历背包
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        return sum - 2 * dp[target];
    }
};

int main() {

	system("pause");
	return 0;
}