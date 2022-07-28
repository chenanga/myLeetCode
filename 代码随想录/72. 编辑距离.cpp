#include <iostream>
#include <vector>

using namespace std;

// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         int len1 = word1.size(), len2 = word2.size();

//         // dp[i][j] ����word1��ǰi�����ʺ�word2��ǰj������֮��ı༭����
//         vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
//         /*
//         ����  dp[i][j] = dp[i-1][j] + 1
//         ɾ����������һ���ַ����룩 dp[i][j] = dp[i][j-1]+1
//         �滻 dp[i][j] = dp[i-1][j-1] + 1
//         */
//         for (int i = 0; i <= len1; ++ i) 
//             dp[i][0] = i;

//         for (int j = 0; j <= len2; ++ j) 
//             dp[0][j] = j;

//         for (int i = 1; i <= len1; ++ i) {
//             for (int j = 1; j <= len2; ++ j) {
//                 if (word1[i - 1] == word2[j - 1])
//                     dp[i][j] = dp[i - 1][j - 1];
//                 else { // word1[i - 1] != word2[j - 1]
//                     dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1));
//                 }
//             }
//         }
//         return dp[len1][len2];

//     }
// };


class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();

        // dp[i][j] ����word1��ǰi�����ʺ�word2��ǰj������֮��ı༭����
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        /*
        ����  dp[i][j] = dp[i-1][j] + 1
        ɾ����������һ���ַ����룩 dp[i][j] = dp[i][j-1]+1
        �滻 dp[i][j] = dp[i-1][j-1] + 1
        */
        for (int i = 0; i <= len1; ++i)
            dp[i][0] = i;

        for (int j = 0; j <= len2; ++j)
            dp[0][j] = j;

        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else { // word1[i - 1] != word2[j - 1]
                    dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
                }
            }
        }
        return dp[len1][len2];

    }
};

int main() {

	system("pause");
	return 0;
}