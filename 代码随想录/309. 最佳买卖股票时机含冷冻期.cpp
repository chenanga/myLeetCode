#include <iostream>
#include <vector>

using namespace std;

/*
��ǰ��4״̬
    0���й�Ʊ: ����֮ǰ���У����߽������루������������������䶳�ڻ�����������״̬��

    δ���й�Ʊ
        1֮ǰ�������ˣ�һֱû�������ȹ����䶳�ڣ�����������״̬�������������䶳��
        2���������ģ� ������У���������

    3�䶳��
    dp[i][0] = max(dp[i-1][0], max(dp[i-1][1] - prices[i], dp[i-1][3] - prices[i]))
    dp[i][1] = max(dp[i-1][1], dp[i-1][3])  // ���Դ��䶳�ڱ����
    dp[i][2] = dp[i-1][0] + prices[i]
    dp[i][3] = dp[i-1][2]

*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len <= 1) return 0;
        vector<vector<int>> dp(len, vector<int>(4, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;
        dp[0][3] = 0;

        for (int i = 1; i < len; ++i) {
            for (int j = 0; j < 4; ++j) {
                // ע������״̬0��ǰ��״̬�ж�����ܣ���Ҫ����ȫ��
                dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1] - prices[i], dp[i - 1][3] - prices[i]));
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
                dp[i][2] = dp[i - 1][0] + prices[i];
                dp[i][3] = dp[i - 1][2];
            }
        }

        return max(dp[len - 1][1], max(dp[len - 1][2], dp[len - 1][3]));

    }
};

int main() {

	system("pause");
	return 0;
}