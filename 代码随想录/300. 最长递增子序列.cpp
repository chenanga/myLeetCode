#include <iostream>
#include <vector>

using namespace std;

// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         // dp[i]代表以i为结尾的子序列最大长度
//         // 不一定是dp[len-1]最长
//         int len = nums.size(), res = 1; // res = dp[0] 效果一样
//         // if (len <= 1) return 0;
//         vector<int> dp(len, 0);
//         dp[0] = 1;

//         for (int i = 1; i < len; ++ i) {
//             int max_len = 0;
//             for (int j = 0; j < i; ++ j) {
//                 if (max_len < dp[j] && nums[j] < nums[i])
//                     max_len = dp[j];
//             }
//             dp[i] = max_len + 1;
//             if (res < dp[i])
//                 res = dp[i];
//         }
//         return res;
//     }
// };

// 优化写法
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // dp[i]代表以i为结尾的子序列最大长度
        // 不一定是dp[len-1]最长
        int len = nums.size(), res = 1; // res = dp[0] 效果一样
        // if (len <= 1) return 0;
        vector<int> dp(len, 1);

        for (int i = 1; i < len; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }

            if (res < dp[i])
                res = dp[i];
        }
        return res;
    }
};

int main() {

	system("pause");
	return 0;
}