#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        /*
            dp[i][j]��ʾ�ַ��� s[i...j]�Ƿ��ǻ��Ĵ�
            if ( s[j] == s[i]) {
                if (j - i <= 1)
                    dp[i][j] = t
                else
                dp[i][j] = dp[i+1][j-1]
            }

        */
        int len = s.size(), res = 0;

        vector<vector<bool>> dp(len, vector<bool>(len, false));
        // ���ȴӵ��ƹ�ʽ�п��Կ�����������Ǹ���dp[i + 1][j - 1]�Ƿ�Ϊtrue���ڶ�dp[i][j]���и�ֵtrue�ġ�����һ��Ҫ���µ��ϣ������ұ�����������֤dp[i + 1][j - 1]���Ǿ�������ġ�

        for (int i = len - 1; i >= 0; --i) {
            for (int j = i; j < len; ++j) {
                if (s[i] == s[j]) {
                    if (j - i <= 1) {
                        dp[i][j] = true;
                        ++res;
                    }
                    else if (dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                        ++res;
                    }

                }
            }
        }
        return res;
    }
};

int main() {

	system("pause");
	return 0;
}