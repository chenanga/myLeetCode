#include <iostream>
#include <vector>

using namespace std;

// f(s)����ɿ�ѡ���s�������СӲ������
// f(s) = f(s-c)+1
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;

        int max = amount + 1;  // ��Ϊ��С��ֵΪ1��������ʹ��amount����ֵΪ1��
        vector<int> dp(amount + 1, max);
        dp[0] = 0;


        for (int i = 1; i <= amount; ++i) {
            for (int j = coins.size() - 1; j >= 0; --j) {
                if (i >= coins[j])
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }

        return max == dp[amount] ? -1 : dp[amount];
    }
};

int main() {

	system("pause");
	return 0;
}