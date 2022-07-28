#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        /*
        dp[i][j] 代表word1 的前i个字符 和 word2的前j个字符相同的最小步数
        if w1[i-1] = w2[j-1]
            dp[i][j] = dp[i-1][j-1]
        else
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1


        */
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));

        for (int j = 1; j <= word2.size(); ++j)
            dp[0][j] = dp[0][j - 1] + 1;

        for (int i = 1; i <= word1.size(); ++i)
            dp[i][0] = dp[i - 1][0] + 1;


        for (int i = 1; i <= word1.size(); ++i) {
            for (int j = 1; j <= word2.size(); ++j) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

int main() {

	system("pause");
	return 0;
}