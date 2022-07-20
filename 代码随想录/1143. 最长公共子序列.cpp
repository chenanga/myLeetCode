#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // dp[i][j]������Ϊ[0, i - 1]���ַ���text1�볤��Ϊ[0, j - 1]���ַ���text2�������������Ϊdp[i][j]
        int len1 = text1.size(), len2 = text2.size();

        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        /*
        if (text1[i] == text2[j])
            dp[i][j] = dp[i-1][j-1] + 1;
        else
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        */

        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

            }
        }
        return dp[len1][len2];
    }
};

int main() {

	system("pause");
	return 0;
}