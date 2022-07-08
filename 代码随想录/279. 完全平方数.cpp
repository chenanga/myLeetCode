#include <iostream>
#include <vector>

using namespace std;

/*
n �Ǳ�������
��ȫƽ��������Ʒ��ÿ����Ʒ�������ߡ�
*/
class Solution {
public:
    int numSquares(int n) {
        int maxNum = sqrt(n);
        // ��ƷΪ1... maxNum��ƽ��
        vector<int> dp(n + 1, 10001);
        // dp[i] λi����ȫƽ��������������
        // dp[i] = min(dp[i-1] + 1, dp[i - 4] + 1, dp[i - maxnum*maxnum] + 1)
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= maxNum; ++j) {
                if (i >= j * j)
                    dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};

int main() {

	system("pause");
	return 0;
}