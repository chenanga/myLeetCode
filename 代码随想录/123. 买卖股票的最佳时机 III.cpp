#include <iostream>
#include <vector>

using namespace std;

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         // �������������ʽ���
//         // һ��һ��������״̬
//         /*
//         û�в���
//         ��һ������
//         ��һ������
//         �ڶ�������
//         �ڶ�������
//         dp[i][j]�� i��ʾ��i�죬jΪ [0 - 4] ���״̬��dp[i][j]��ʾ��i��״̬j��ʣ����ֽ�
//         dp[i][1]����ʾ���ǵ�i�죬�ǵ�һ�������Ʊ��״̬

//         dp[i][0] = dp[i-1][0];
//         dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])
//         dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i])
//         dp[i][3] = max(dp[i-1][3], dp[i-1][2] - prices[i])
//         dp[i][4] = max(dp[i-1][4], dp[i-1][3] + prices[i])
//         */
//         int len = prices.size();
//         vector<vector<int>> dp(len, vector<int>(5, 0));
//         dp[0][0] = 0;
//         dp[0][1] = -prices[0];
//         dp[0][2] = 0;
//         dp[0][3] = -prices[0];
//         dp[0][4] = 0;

//         for (int i = 1; i < len; ++ i) {
//             dp[i][0] = dp[i-1][0];
//             dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
//             dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i]);
//             dp[i][3] = max(dp[i-1][3], dp[i-1][2] - prices[i]);
//             dp[i][4] = max(dp[i-1][4], dp[i-1][3] + prices[i]);          
//         }
//         return max(dp[len - 1][0], max(dp[len - 1][2], dp[len - 1][4]));

//     }
// };


// �ռ��Ż�
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int len = prices.size();
        vector<int> dp(5, 0);
        dp[0] = 0;
        dp[1] = -prices[0];
        dp[2] = 0;
        dp[3] = -prices[0];
        dp[4] = 0;

        for (int i = 1; i < len; ++i) {
            // dp[2]���õ��ǵ����dp[1]�� �����Ҳ�ǶԵġ�
            /*
            dp[1] = max(dp[1], dp[0] - prices[i]); ���dp[1]ȡdp[1]�������������Ʊ��״̬��
            ��ô dp[2] = max(dp[2], dp[1] + prices[i]);��dp[1] + prices[i] ���ǽ���������
            ���dp[1]ȡdp[0] - prices[i]�����������Ʊ����ôdp[2] = max(dp[2], dp[1] + prices[i]);
            �е�dp[1] + prices[i]�൱���Ǿ�����������Ʊ��һ��һ������Ϊ0���������ֽ�û��Ӱ�졣
            �൱�ڽ��������Ʊ��������Ʊ������û�в�������������������Ʊ��״̬�ˡ�
            */
            dp[1] = max(dp[1], dp[0] - prices[i]);
            dp[2] = max(dp[2], dp[1] + prices[i]);
            dp[3] = max(dp[3], dp[2] - prices[i]);
            dp[4] = max(dp[4], dp[3] + prices[i]);
        }
        return max(dp[0], max(dp[2], dp[4]));

    }
};

int main() {

	system("pause");
	return 0;
}