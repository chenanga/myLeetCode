#include <iostream>
#include <vector>

using namespace std;

// // ��ʱ��  14 / 28 ��ͨ����������
// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         sort(coins.begin(), coins.end());
//         result = 0;
//         // ���ʹ�õ�Ӳ������
//         maxCoins = amount / coins[0] + 1;
//         __change(amount, coins, 0, 0, 0);
//         return result;

//     }

// private:
//     int result, maxCoins;
//     void __change(int amount, vector<int>& coins, int count, int sum, int index) {
//         if (count > maxCoins && sum != amount)
//             return;
//         if (sum == amount) {
//             result ++;
//             return;
//         }

//         for (int i = index; i < coins.size(); ++ i) {
//             __change(amount, coins, count + 1, sum + coins[i], i);
//         }
//         return;
//     }
// };


// // ��̬�滮,ʱ�仹���е㳤����Ϊ��ȷ��ÿ���ü�����ǰӲ�ң����Զ���һ��ѭ��
// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         int len = coins.size();
//         vector<int> dp(amount + 1, 0);  //dp[i][j]����coins[0..i]�ܱ�ʾ�Ľ��Ϊj��������
//         // dp[i][j] = dp[i-1][j] + dp[i - 1][j - coins[i]];
//         // ��ʼ��

//         for (int j = 0; j <= amount; ++ j) {
//             if (j % coins[0] == 0) 
//                 dp[j] = 1;
//         }

//         for (int i = 1; i < len; ++ i) {
//             for (int j = amount; j >= coins[i] ; -- j) {
//                 for (int k = 1; k <= j / coins[i]; ++ k) {
//                     // ʹ��0��Ӳ�ҵ�j/coins[i]��Ӳ��
//                     if (j >= k * coins[i])
//                         dp[j] += dp[j - k * coins[i]];  
//                 }
//             }
//         }
//         return dp[amount];    
//     }
// };

// ��̬�滮
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int len = coins.size();
        vector<int> dp(amount + 1, 0);  //dp[i][j]����coins[0..i]�ܱ�ʾ�Ľ��Ϊj��������
        // dp[j] += dp[j - coins[i]];
        // ��ʼ��

        dp[0] = 1;
        for (int i = 0; i < len; ++i) {
            for (int j = coins[i]; j <= amount; ++j) {
                dp[j] += dp[j - coins[i]];

            }
        }
        return dp[amount];
    }
};

int main() {

	system("pause");
	return 0;
}