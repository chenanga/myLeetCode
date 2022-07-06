#include <iostream>
#include <vector>

using namespace std;

// // �ݹ�  9 / 15 ��ͨ����������
// class Solution {
// public:
//     int combinationSum4(vector<int>& nums, int target) {
//         result = 0;
//         vector<int>temp;
//         __combinationSum4(nums, target, 0);
//         return result;
//     }
// private:
//     int result;
//     void __combinationSum4(vector<int>& nums, int target, int sum) {
//         if (sum > target) return;
//         if (sum == target) {
//             result ++;
//             return;
//         }

//         for (int i = 0; i < nums.size(); ++ i) {
//             __combinationSum4(nums, target, sum + nums[i]);
//         }
//         return ;
//     }
// };


// ��̬�滮
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // dp[i][j]��ʾ�ܹ��� j�������
        int len = nums.size();
        // vector<vector<int>> dp(len, vector<int>(target + 1, 0));
        // dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i]] + dp[i-1][j-2*nums[i]] ....+
        // dp[j] += dp[j - nums[i]]  ���������˳����ˣ�����i��j����
        vector<int> dp(target + 1, 0);

        dp[0] = 1;
        for (int i = 0; i <= target; ++i) {
            for (int j = 0; j < len; ++j) {
                // �����������������ˣ���ֹ�������������������ⲻӰ����
                //С�Ż�ֱ��ʹ��int���顣dp[i] + dp[i-nums[j]] < INT_MAX ǰ�沿�ֿ��ܻ������ֱ�ӱ�������ʹ�� dp[i] < INT_MAX - dp[i-nums[j]]
                if (i >= nums[j] && dp[i] < INT_MAX - dp[i - nums[j]])
                    dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
    }

};



int main() {

	system("pause");
	return 0;
}