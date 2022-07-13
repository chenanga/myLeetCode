#include <iostream>
#include <vector>

using namespace std;

// // ̰����ÿ�������ľ����ܶ�
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         if (prices.size() == 1) return 0;
//         if (prices.size() == 2) return max(0, prices[1] - prices[0]);


//         // preDiff�����ϴ�������׬��Ǯ
//         int preDiff = prices[1] - prices[0], result = 0;

//         for (int i = 2; i < prices.size(); ++ i) {

//             // ����ϴ�������׬��Ǯ�����ģ����ҵ�ǰ����һ�μ۸���ߣ���ô�ڽ�����������׬�ĸ��࣬����preDiff
//             if (preDiff > 0 && prices[i] > prices[i - 1]) {
//                 preDiff += (prices[i] - prices[i - 1]);
//                 if (i == prices.size() - 1)  // �����ÿ�춼�ǵ����ļ۸���resultû�ñ����£�����ط��Ӹ��ж�
//                     result += preDiff;
//             }

//             // ����ϴ�����׬��Ǯ���� �ģ����ǽ���۸������ͣ���ô����Ϊ��������������result
//             else if (preDiff > 0 && prices[i] <= prices[i - 1]) {
//                 result += preDiff;
//                 preDiff = prices[i] - prices[i - 1];
//             }

//             //
//             else {  // preDiff <= 0
//                 preDiff = prices[i] - prices[i - 1];
//                 if (i == prices.size() - 1 && preDiff > 0)  //����պ����һ������Ǯ����ô����result 
//                     result += preDiff;
//             }


//         }
//         return result;
//     }
// };


// // ̰��2���ָ�һ��һ����С���䣬�ռ���������
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {

//         int result = 0;

//         for (int i = 1; i < prices.size(); ++ i) {

//             if (prices[i] - prices[i - 1] > 0)
//                 result += prices[i] - prices[i - 1];
//         }

//         return result;
//     }
// };


// ��̬�滮
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 1) return 0;
        else if (len == 2) return max(0, prices[1] - prices[0]);

        vector<int> dp(len, 0);
        // dp[i]����ǰ����i���õ��������
        // �������������Ʊ�۸�ͣ���ô���������������������������
        // �������������Ʊ�۸�ߣ���ô�����������������������������������򣬽�����������
        // dp[i] = max(dp[i-1], dp[i-1] + prices[i] - prices[i-1]);

        dp[0] = 0;

        for (int i = 1; i < len; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 1] + prices[i] - prices[i - 1]);
        }
        return dp[len - 1];

    }
};

int main() {

	system("pause");
	return 0;
}