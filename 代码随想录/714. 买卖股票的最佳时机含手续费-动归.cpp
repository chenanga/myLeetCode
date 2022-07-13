#include <iostream>
#include <vector>

using namespace std;

// ̰��
// class Solution {
// public:
//     int maxProfit(vector<int>& prices, int fee) {
//         int result = 0;
//         int minPrice = prices[0];
//         for (int i = 0; i < prices.size(); ++ i) {
//             // ������ͼ۸�
//             if (prices[i] < minPrice) minPrice = prices[i];

//             // if (prices[i] - minPrice <= fee)  // ����ʡ��
//             //     continue; 
//             if (prices[i] > minPrice + fee) {
//                 result += (prices[i] - minPrice - fee);
//                 minPrice = prices[i] - fee;  // �����������
//                 /*
//                 ���Ǵ�ʱ������Ʊ���ܲ�����ȫ�����ŵģ�������һ���Ʊ�۸������������
//                 ������ǿ����ṩһ�����ڲ��������ɵ�ǰ����ӵ��һ֧����۸�Ϊ prices[i] �Ĺ�Ʊ
//                 �����һ���Ʊ������������ô׬��Ǯ��prices[i+1] - minprices, ��ʱ���������ѱ���ǰ����               �ˣ��൱���������һ���׵�


//                 */
//             }
//         }
//         return result;
//     }
// };

//  ��̬�滮
/*
dp[i][0] ��ʾ��i����й�Ʊ��ʡ����ֽ� dp[i][1] ��ʾ��i�첻���й�Ʊ��������ֽ�

    dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i])
    dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i] - fee)
*/
// class Solution {
// public:
//     int maxProfit(vector<int>& prices, int fee) {
//         int len = prices.size();
//         if (len <= 1) return 0;

//         vector<vector<int>> dp(len, vector<int>(2, 0));
//         dp[0][0] = -prices[0];
//         dp[0][1] = 0;

//         for (int i = 1; i < len; ++ i) {
//             dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i]);
//             dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i] - fee);
//         }
//         // return max(dp[len-1][0], dp[len-1][1]);
//         // ���һ��϶��ǲ����й�Ʊ���
//         return dp[len-1][1];

//     }
// };

// ���� �ռ��Ż�
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int len = prices.size();
        if (len <= 1) return 0;

        vector<int> pre(2, 0);
        vector<int> cur(2, 0);

        pre[0] = -prices[0];
        pre[1] = 0;

        for (int i = 1; i < len; ++i) {
            cur[0] = max(pre[0], pre[1] - prices[i]);
            cur[1] = max(pre[1], pre[0] + prices[i] - fee);
            pre = cur;
        }

        // ���һ��϶��ǲ����й�Ʊ���
        return cur[1];

    }
};

int main() {

	system("pause");
	return 0;
}