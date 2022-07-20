#include <iostream>
#include <vector>

using namespace std;

// // 动态规划
// class Solution {
// public:
//     int findLengthOfLCIS(vector<int>& nums) {
//         // dp[i]为以i结尾的最长连续递增子序列
//         int len = nums.size(), res = 1;
//         vector<int> dp(len, 1);

//         for (int i = 1; i < len; ++ i) {
//             if (nums[i] > nums[i - 1])
//                 dp[i] = dp[i - 1] + 1;

//             if (res < dp[i])
//                 res = dp[i];
//         }
//         return res;
//     }
// };

// 贪心
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        // dp[i]为以i结尾的最长连续递增子序列
        int len = nums.size(), res = 1, count = 1;

        for (int i = 1; i < len; ++i) {
            if (nums[i] > nums[i - 1])
                count++;
            else
                count = 1;
            if (res < count)
                res = count;
        }
        return res;
    }
};

int main() {

	system("pause");
	return 0;
}