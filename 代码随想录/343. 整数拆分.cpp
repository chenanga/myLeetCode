#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);  // dp[0] = dp[1] = 0

        for (int i = 2; i <= n; ++i)
            for (int j = 1; j < i; ++j)  // 这里j < i 和 j < i - 1都可以通过
                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));

        return dp[n];
    }
};

int main() {

	system("pause");
	return 0;
}