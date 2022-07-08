#include <iostream>
#include <vector>

using namespace std;

// class Solution {
// public:
//     int climbStairs(int n) {
//         // fn = fn-2 + fn-1
//         if (n <= 2) return n;
//         vector<int> dp(n + 1, 1);  //dp[1]=1
//         dp[2] = 2;
//         for (int i = 3; i <= n; ++ i) {
//             dp[i] = dp[i - 1] + dp[i - 2];
//         }
//         return dp[n];
//     }
// };

// 可以理解为有两个面值的硬币，硬币数量无线，问有多少种排列方式使得硬币总量为n
class Solution {
public:
    int climbStairs(int n) {
        int m = 2; // 一次能走一层或两层楼梯，这个解法可以是任意层楼梯

        vector<int> dp(n + 1, 0);  //dp[i] 为有多少种组合到达i层
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (i >= j)
                    dp[i] += dp[i - j];
            }
        }
        return dp[n];
    }
};

int main() {

	system("pause");
	return 0;
}