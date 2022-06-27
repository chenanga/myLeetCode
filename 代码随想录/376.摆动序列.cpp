#include<iostream>
#include<vector>

using namespace std;

// class Solution {
// public:
//     int wiggleMaxLength(vector<int>& nums) {
//         int len = nums.size();
//         //动态规划
//         //memo[i][0] 为第i个元素结尾的降序的最大摆动序列，降序指的是上一个元素到元素i是降序
//         //memo[i][1] 为第i个元素结尾的升序的最大摆动序列，升序指的是上一个元素到元素i是升序
//         //当nums[i] > nums[i-1],则以i结尾的的降序序列的最大值只能是以i-1结尾的最大值
//         vector<vector<int>> memo(len, vector<int>(2, 1)); //包含初始化

//         for (int i = 1; i < len; ++ i) {
//             if (nums[i] < nums[i - 1]) {
//                 memo[i][0] = max(memo[i - 1][1] + 1, memo[i - 1][0]);
//                 memo[i][1] = memo[i - 1][1];
//             }
//             else if (nums[i] > nums[i - 1]) {
//                 memo[i][0] = memo[i - 1][0];
//                 memo[i][1] = max(memo[i - 1][0] + 1, memo[i - 1][1]);
//             }
//             else { //nums[i] == nums[i - 1]
//                 memo[i][0] = memo[i - 1][0];
//                 memo[i][1] = memo[i - 1][1];
//             }
//         }
//         return max(memo[len - 1][0], memo[len - 1][1]);
//     }
// };

// //使用滚动数组1
// class Solution {
// public:
//     int wiggleMaxLength(vector<int>& nums) {
//         int len = nums.size();
//         //动态规划
//         //memo[i][0] 为第i个元素结尾的降序的最大摆动序列，降序指的是上一个元素到元素i是降序
//         //memo[i][1] 为第i个元素结尾的升序的最大摆动序列，升序指的是上一个元素到元素i是升序
//         //当nums[i] > nums[i-1],则以i结尾的的降序序列的最大值只能是以i-1结尾的最大值
//         int preUp = 1, preDown = 1;
//         int curUp = 1, curDown = 1;

//         for (int i = 1; i < len; ++ i) {
//             if (nums[i] < nums[i - 1]) {
//                 curDown = max(preUp + 1, preDown);
//                 curUp = preUp;
//             }
//             else if (nums[i] > nums[i - 1]) {
//                 curUp = max(preDown + 1, preUp);
//                 curDown = preDown;

//             }
//             else { //nums[i] == nums[i - 1]
//                 curDown = preDown;
//                 curUp = preUp;
//             }
//             preDown = curDown;
//             preUp = curUp;
//         }
//         return max(preDown, preUp);
//     }
// };

//使用滚动数组2
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();
        //动态规划
        //memo[i][0] 为第i个元素结尾的降序的最大摆动序列，降序指的是上一个元素到元素i是降序
        //memo[i][1] 为第i个元素结尾的升序的最大摆动序列，升序指的是上一个元素到元素i是升序
        //当nums[i] > nums[i-1],则以i结尾的的降序序列的最大值只能是以i-1结尾的最大值
        int preUp = 1, preDown = 1;

        for (int i = 1; i < len; ++i) {
            if (nums[i] < nums[i - 1])
                preDown = max(preUp + 1, preDown);

            else if (nums[i] > nums[i - 1])
                preUp = max(preDown + 1, preUp);

        }
        return max(preDown, preUp);
    }
};

int main() {

	system("pause");
	return 0;
}