#include <iostream>
#include <vector>

using namespace std;

// // 递归
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

//         // 当前是加号或者减号
//         __findTargetSumWays(nums, target - nums[index], index + 1);
//         __findTargetSumWays(nums, target + nums[index], index + 1);
//         return;
//     }
// };

// 动态规划
// 重要的是公式推导
// left - right = target     ,left: 数字前面添加加号的，right数字前面加减号的
// left + right = sum
// left = (target + sum) / 2 
// 转换为在nums[]中挑选和为left的可能性有几种
// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int len = nums.size(), sum = 0;
//         for (int num : nums)
//             sum += num;
//         if ((target + sum) % 2 == 1 || target > sum || target < -sum )return 0;
//         int left = (target + sum) / 2;

//         vector<vector<int>> dp(len, vector<int>(left + 1, 0));
//         /* dp[i][j] 表示在nums[0...i]中挑选出和为j的数目总数
//         dp[i][j] = dp[i-1][j] + dp[i - 1][j - nums[i]];
//         */
//         // 初始化第一行
//         for (int i = 0; i <= left; ++ i)
//             if (nums[0] == i)
//                 dp[0][i] = 1;
//         dp[0][0] = (nums[0] == 0) ? 2 : 1;  // 不挑也是一种方案，当nums[0]为0时候，dp[0][0]=2,此时可以选择0前面加正或是负
//         for (int i = 1; i < len; ++ i) {
//             for (int j = 0; j <= left; ++ j) {
//                 dp[i][j] = dp[i - 1][j] + (j - nums[i] >= 0 ? dp[i - 1][j - nums[i]] : 0);
//             }
//         }
//         return dp[len - 1][left];
//     }

// };

// 空间优化，使用一行数组
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int len = nums.size(), sum = 0;
        for (int num : nums)
            sum += num;
        if ((target + sum) % 2 == 1 || target > sum || target < -sum)return 0;
        int left = (target + sum) / 2;

        vector<int> dp(left + 1, 0);
        /* dp[i][j] 表示在nums[0...i]中挑选出和为j的数目总数
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


// 之前的参考官方的
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