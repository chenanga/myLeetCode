#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        /*
            dp[i][j]��ʾ�ַ��� s[i...j]�л��������еĳ���
        */
        int len = s.size();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        for (int i = 0; i < len; ++i)
            dp[i][i] = 1;

        for (int i = len - 1; i >= 0; --i) {
            for (int j = i + 1; j < len; ++j) {
                if (s[j] == s[i])
                    dp[i][j] = dp[i + 1][j - 1] + 2;

                else   // �ؼ���ȷ����߼�һ��s[i]�����������ұ߼�һ��s[j]�������������Ǹ�
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