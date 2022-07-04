#include <iostream>
#include <vector>

using namespace std;


//����������
/*
G(n)����n��������ɵĶ����������ĸ���
f(i,n)������iΪ���ڵ㣬n��������ɵ�����
G(n) = f(1,n) + f(2,n) + ... + f(n,n)
f(i,n) = g(i-1) * g(n-i)
g(0) = g(1) = 1
g(2) = 2
G(n) = g(1-1) * g(n-1) + g(2-1) * g(n-2) + g(i-1) * g(n-i)
*/
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;  // Ϊ�˺���ʹ��ʱ������
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j)
                dp[i] += dp[i - j] * dp[j - 1];
        }
        return dp[n];
    }
};

int main() {

	system("pause");
	return 0;
}