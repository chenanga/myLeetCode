#include <iostream>
#include <vector>

using namespace std;
// class Solution {
// public:
//     bool isSubsequence(string s, string t) {
//         int len_s = s.size(), len_t = t.size();

//         if (len_s == 0 && len_t >= 0) 
//             return true;
//         else if (len_t == 1 && len_t == 1)
//             return s[0] == t[0];
//         else if (len_s == 1 && len_t == 0)
//             return false;

//         vector<vector<bool>> dp(len_s + 1, vector<bool>(len_t + 1, false));
//         /*
//         ���г�ʼ��Ϊtrue����Ҫ��ʼ������,����ֻ�е�һ��Ϊtrue������false
//         dp[i][j] ����s[i]ǰi��Ԫ���� t[j]��ǰjԪ�ص�������
//         */
//         for (int j = 0; j <= len_t; ++ j)
//             dp[0][j] = true;

//         for (int i = 1; i <= len_s; ++ i) {
//             for (int j = 1; j <= len_t; ++ j) {
//                 if (s[i - 1] == t[j - 1])
//                     dp[i][j] = dp[i - 1][j - 1];
//                 else
//                     dp[i][j] = dp[i][j - 1];
//             }
//         }

//         // for (int i = 0; i <= len_s; ++ i) {
//         //     for (int j = 0; j <= len_t; ++ j) {
//         //         cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;

//         //     }
//         // }

//         return dp[len_s][len_t];
//     }
// };


class Solution {
public:
    bool isSubsequence(string s, string t) {
        int len_s = s.size(), len_t = t.size();

        vector<vector<bool>> dp(len_s + 1, vector<bool>(len_t + 1, false));
        /*
        ���г�ʼ��Ϊtrue����Ҫ��ʼ������,����ֻ�е�һ��Ϊtrue������false
        dp[i][j] ����s[i]ǰi��Ԫ���� t[j]��ǰjԪ�ص�������
        */
        for (int j = 0; j <= len_t; ++j)
            dp[0][j] = true;

        for (int i = 1; i <= len_s; ++i) {
            for (int j = 1; j <= len_t; ++j) {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }


        return dp[len_s][len_t];
    }
};
int main() {

	system("pause");
	return 0;
}