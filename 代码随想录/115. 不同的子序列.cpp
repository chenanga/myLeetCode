#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(t.size() + 1, vector<int>(s.size() + 1, 0));
        /* dp[i][j] 代表t前i个元素和 s前j个元素 子序列个数 */
        for (int j = 0; j <= s.size(); ++j)
            dp[0][j] = 1;

        for (int i = 1; i <= t.size(); ++i) {
            for (int j = 1; j <= s.size(); ++j) {
                if (s[j - 1] == t[i - 1]) {
                    // 不满足部分直接忽略，不影响最终结果
                    if (dp[i - 1][j - 1] < INT_MAX - dp[i][j - 1])
                        dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                }
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }

        return dp[t.size()][s.size()];
    }
};

int main() {

	system("pause");
	return 0;
}