#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        // ת��Ϊ�������⣬
        int sum = 0, len = stones.size();
        for (int i = 0; i < len; ++i)
            sum += stones[i];
        int target = sum / 2;
        vector<int> dp(target + 1, 0);
        // dp[j]��ʾ����������˵������������ʵ����������Ϊj�ı����������Ա�dp[j]��ô�ص�ʯͷ��
        // ��ʼ��Ϊ0
        // dp[i] = max(dp[i], dp[i - stones[i]] + stones[i])
        for (int i = 0; i < len; ++i) // ������Ʒ
            for (int j = target; j >= stones[i]; --j) { // ��������
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        return sum - 2 * dp[target];
    }
};

int main() {

	system("pause");
	return 0;
}