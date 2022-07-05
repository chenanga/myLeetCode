#include <iostream>
#include <vector>

using namespace std;

// // �ݹ�
// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         result = 0;
//         __findTargetSumWays(nums, target, 0);
//         return result;
//     }
// private:
//     int result;
//     void __findTargetSumWays(vector<int>& nums, int target, int index) {
//         if (index == nums.size()) {
//             if (target == 0)
//                 result ++;
//             return;
//         }

//         // ��ǰ�ǼӺŻ��߼���
//         __findTargetSumWays(nums, target - nums[index], index + 1);
//         __findTargetSumWays(nums, target + nums[index], index + 1);
//         return;
//     }
// };

// ��̬�滮
// ��Ҫ���ǹ�ʽ�Ƶ�
// left - right = target     ,left: ����ǰ����ӼӺŵģ�right����ǰ��Ӽ��ŵ�
// left + right = sum
// left = (target + sum) / 2 
// ת��Ϊ��nums[]����ѡ��Ϊleft�Ŀ������м���
// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int len = nums.size(), sum = 0;
//         for (int num : nums)
//             sum += num;
//         if ((target + sum) % 2 == 1 || target > sum || target < -sum )return 0;
//         int left = (target + sum) / 2;

//         vector<vector<int>> dp(len, vector<int>(left + 1, 0));
//         /* dp[i][j] ��ʾ��nums[0...i]����ѡ����Ϊj����Ŀ����
//         dp[i][j] = dp[i-1][j] + dp[i - 1][j - nums[i]];
//         */
//         // ��ʼ����һ��
//         for (int i = 0; i <= left; ++ i)
//             if (nums[0] == i)
//                 dp[0][i] = 1;
//         dp[0][0] = (nums[0] == 0) ? 2 : 1;  // ����Ҳ��һ�ַ�������nums[0]Ϊ0ʱ��dp[0][0]=2,��ʱ����ѡ��0ǰ��������Ǹ�
//         for (int i = 1; i < len; ++ i) {
//             for (int j = 0; j <= left; ++ j) {
//                 dp[i][j] = dp[i - 1][j] + (j - nums[i] >= 0 ? dp[i - 1][j - nums[i]] : 0);
//             }
//         }
//         return dp[len - 1][left];
//     }

// };

// �ռ��Ż���ʹ��һ������
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int len = nums.size(), sum = 0;
        for (int num : nums)
            sum += num;
        if ((target + sum) % 2 == 1 || target > sum || target < -sum)return 0;
        int left = (target + sum) / 2;

        vector<int> dp(left + 1, 0);
        /* dp[i][j] ��ʾ��nums[0...i]����ѡ����Ϊj����Ŀ����
        dp[i][j] = dp[i-1][j] + dp[i - 1][j - nums[i]];
        */
        dp[0] = 1;

        for (int i = 0; i < len; ++i) {
            for (int j = left; j >= nums[i]; --j) {
                dp[j] = dp[j] + dp[j - nums[i]];
            }
        }
        return dp[left];
    }

};


// ֮ǰ�Ĳο��ٷ���
// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int sum = 0;
//         for(int i : nums)
//             sum += i;
//         if(sum - target < 0 || (sum-target)%2 == 1)
//             return 0;
//         int neg = (sum - target) / 2;
//         int n = nums.size();
//         vector<vector<int>>memo (n + 1, vector<int>(neg + 1, 0));
//         memo[0][0] = 1;

//         for(int i = 1; i <= n; i ++){
//             for(int j = 0; j <= neg; j ++){
//                 if(j < nums[i-1])
//                     memo[i][j] = memo[i-1][j];
//                 else
//                     memo[i][j] = memo[i-1][j] + memo[i-1][j-nums[i-1]]; 
//             }
//         }
//         return memo[n][neg];
//     }
// };

int main() {

	system("pause");
	return 0;
}