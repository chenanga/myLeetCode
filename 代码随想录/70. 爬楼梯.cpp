#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        // fn = fn-2 + fn-1
        if (n <= 2) return n;
        vector<int> dp(n + 1, 1);  //dp[1]=1
        dp[2] = 2;
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

int main() {

	system("pause");
	return 0;
}