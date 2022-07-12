#include <iostream>
#include <vector>

using namespace std;

// �Լ��ķ�����
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int left = 0, right = prices.size();
//         // dp[i] ��ʾ��i���������������
//         // dp[i] = dp[i-1] + prices[i] - prices[i-1];

//         vector<int> dp(prices.size(), 0);
//         int res = 0, minprice = prices[0];
//         dp[0] = 0;
//         for (int i = 1; i < prices.size(); ++ i) {
//             minprice = min(minprice, prices[i]);
//             dp[i] = prices[i] - minprice;
//             if (dp[i] > res)
//                 res = dp[i];
//         }
//         return res;
//     }
// };

// �Ż�����ʵdp�������û���ϣ�ֻ�ü�¼���ֵ������ȥ������
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int res = 0, minprice = INT_MAX;

        for (int i = 0; i < prices.size(); ++i) {
            minprice = min(minprice, prices[i]);
            res = max(res, prices[i] - minprice);

        }
        return res;
    }
};

int main() {

	system("pause");
	return 0;
}