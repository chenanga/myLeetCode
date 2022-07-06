#include <iostream>
#include <vector>

using namespace std;

// // 递归  9 / 15 个通过测试用例
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


// 动态规划
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // dp[i][j]表示能构成 j的组合数
        int len = nums.size();
        // vector<vector<int>> dp(len, vector<int>(target + 1, 0));
        // dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i]] + dp[i-1][j-2*nums[i]] ....+
        // dp[j] += dp[j - nums[i]]  由于内外侧顺序变了，所以i和j调换
        vector<int> dp(target + 1, 0);

        dp[0] = 1;
        for (int i = 0; i <= target; ++i) {
            for (int j = 0; j < len; ++j) {
                // 有两个数组相机溢出了，防止溢出，溢出跳过，由题意不影响结果
                //小优化直接使用int数组。dp[i] + dp[i-nums[j]] < INT_MAX 前面部分可能会溢出，直接报错。可以使用 dp[i] < INT_MAX - dp[i-nums[j]]
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