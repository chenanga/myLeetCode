#include <iostream>
#include <vector>

using namespace std;


/*
         0û�в���
         1��һ������
         2��һ������
         3�ڶ�������
         4�ڶ�������
         ...

         �������룬ż������
         dp[i][j]��ʾ��i��״̬j��ʣ����ֽ�
         0 <= j <= 2 * k
*/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if (len <= 1 || k == 0) return 0;

        vector<vector<int>> dp(len, vector<int>(2 * k + 1, 0));

        // ��ʼ��
        for (int j = 0; j <= 2 * k; ++j) {
            if (j % 2 == 1)
                dp[0][j] = -prices[0];
        }

        for (int i = 1; i < len; ++i) {
            for (int j = 0; j <= 2 * k; ++j) {
                if (j == 0)
                    dp[i][j] = dp[i - 1][j];
                else if (j % 2 == 1)  // ��ǰ������
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
                else  // j % 2 == 0     ��ǰ������
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i]);
            }
        }

        // int res = 0;
        // for (int j = 0; j <= 2 * k; ++ j)
        //     res = max(res, dp[len - 1][j]);
        // return res;

        // ���һ������һ��������
        return dp[len - 1][2 * k];
    }
};

int main() {

	system("pause");
	return 0;
}