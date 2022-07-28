#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        /*
            dp[i][j]表示字符串 s[i...j]中回文子序列的长度
        */
        int len = s.size();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        for (int i = 0; i < len; ++i)
            dp[i][i] = 1;

        for (int i = len - 1; i >= 0; --i) {
            for (int j = i + 1; j < len; ++j) {
                if (s[j] == s[i])
                    dp[i][j] = dp[i + 1][j - 1] + 2;

                else   // 关键是确定左边加一个s[i]的数量，和右边加一个s[j]的数量中最大的那个
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][len - 1];
    }
};

int main() {

	system("pause");
	return 0;
}