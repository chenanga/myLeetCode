#include <iostream>
#include <vector>

using namespace std;

// // ��̬�滮
// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int len = cost.size();
//         vector<int> dp(len + 1, 0);  // ����dp[i] Ϊ��¥�µ���i��̨�׵���ͷ���
//         /*
//         dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2])
//         */
//         dp[0] = 0, dp[1] = 0; // ���ڿ��Դ�0����1��ʼſ��������������ʼ��Ϊ0

//         for (int i = 2; i <= len; ++ i) {
//             dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
//         }
//         return dp[len];
//     }
// };

// ��̬�滮, �ռ��Ż�
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        vector<int> dp(3, 0);  // ����dp[i] Ϊ��¥�µ���i��̨�׵���ͷ���
        /*
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2])
        */
        dp[0] = 0, dp[1] = 0; // ���ڿ��Դ�0����1��ʼſ��������������ʼ��Ϊ0

        for (int i = 2; i <= len; ++i) {
            dp[2] = min(dp[1] + cost[i - 1], dp[0] + cost[i - 2]);
            dp[0] = dp[1];
            dp[1] = dp[2];
        }
        return dp[2];
    }
};



int main() {

	system("pause");
	return 0;
}