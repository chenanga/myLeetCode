#include <iostream>
#include <vector>

using namespace std;

// class Solution {
// public:
//     int climbStairs(int n) {
//         // fn = fn-2 + fn-1
//         if (n <= 2) return n;
//         vector<int> dp(n + 1, 1);  //dp[1]=1
//         dp[2] = 2;
//         for (int i = 3; i <= n; ++ i) {
//             dp[i] = dp[i - 1] + dp[i - 2];
//         }
//         return dp[n];
//     }
// };

// �������Ϊ��������ֵ��Ӳ�ң�Ӳ���������ߣ����ж��������з�ʽʹ��Ӳ������Ϊn
class Solution {
public:
    int climbStairs(int n) {
        int m = 2; // һ������һ�������¥�ݣ�����ⷨ�����������¥��

        vector<int> dp(n + 1, 0);  //dp[i] Ϊ�ж�������ϵ���i��
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (i >= j)
                    dp[i] += dp[i - j];
            }
        }
        return dp[n];
    }
};

int main() {

	system("pause");
	return 0;
}