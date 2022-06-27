#include<iostream>
#include<vector>

using namespace std;

// //暴力法
// //超时了  201 / 209 个通过测试用例
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int len = nums.size();
//         int res = -10001;
//         //memo[i][j] 表示nums[i,j]中最大的和的连续子数组
//         vector<vector<int>> memo(len, vector<int>(len, 0));

//         for (int i = 0; i < len; ++ i) {
//             memo[i][i] = nums[i];
//             res = max(res, memo[i][i]);
//         }

//         for (int i = 0; i < len; ++ i) {
//             for (int j = i + 1; j < len; ++ j) {
//                 memo[i][j] = memo[i][j - 1] + nums[j];
//                 res = max(res, memo[i][j]);
//             }
//         }
//         return res;
//     }

// };


// //动态规划，重新定义数组,一维数组即可
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int len = nums.size();
//         int res = nums[0];

//         //memo[i] 表示nums[]以i结尾的最大的和
//         vector<int> memo(len, 0);
//         memo[0] = nums[0];

//         for (int i = 1; i < len; ++ i) {
//             memo[i] = max(memo[i - 1] + nums[i], nums[i]);
//             res = max(res, memo[i]);
//         }

//         return res;
//     }
// };

// //动态规划，使用两个变量代替一维数组，因为此刻状态之和上一时刻有关
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int len = nums.size();
//         int res = nums[0];

//         //memo[i] 表示nums[]以i结尾的最大的和
//         int pre = nums[0];

//         for (int i = 1; i < len; ++ i) {
//             pre = max(pre + nums[i], nums[i]);
//             res = max(res, pre);
//         }

//         return res;
//     }
// };
// 贪心
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int res = nums[0];
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            count += nums[i];
            if (count > res)
                res = count;
            if (count <= 0) count = 0; //重置起始位置
        }
        return res;
    }
};

/*
局部最优：当前“连续和”为负数的时候立刻放弃，从下一个元素重新计算“连续和”，因为负数加上下一个元素 “连续和”只会越来越小。

全局最优：选取最大“连续和”

局部最优的情况下，并记录最大的“连续和”，可以推出全局最优。
*/

int main() {

	system("pause");
	return 0;
}