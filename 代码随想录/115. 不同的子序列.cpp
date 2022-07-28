#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(t.size() + 1, vector<int>(s.size() + 1, 0));
        /* dp[i][j] ����tǰi��Ԫ�غ� sǰj��Ԫ�� �����и��� */
        for (int j = 0; j <= s.size(); ++j)
            dp[0][j] = 1;

        for (int i = 1; i <= t.size(); ++i) {
            for (int j = 1; j <= s.size(); ++j) {
                if (s[j - 1] == t[i - 1]) {
                    // �����㲿��ֱ�Ӻ��ԣ���Ӱ�����ս��
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