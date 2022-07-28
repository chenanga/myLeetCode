#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        /*
            dp[i][j]表示字符串 s[i...j]是否是回文串
            if ( s[j] == s[i]) {
                if (j - i <= 1)
                    dp[i][j] = t
                else
                dp[i][j] = dp[i+1][j-1]
            }

        */
        int len = s.size(), res = 0;

        vector<vector<bool>> dp(len, vector<bool>(len, false));
        // 首先从递推公式中可以看出，情况三是根据dp[i + 1][j - 1]是否为true，在对dp[i][j]进行赋值true的。所以一定要从下到上，从左到右遍历，这样保证dp[i + 1][j - 1]都是经过计算的。

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