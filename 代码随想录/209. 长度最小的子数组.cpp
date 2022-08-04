#include "general.h"
// //暴力
// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int res = nums.size() + 1;
//         for (int i = 0; i < nums.size(); ++ i) {
//             int sum = 0;
//             for (int j = i; j < nums.size(); ++ j) {

//                 sum += nums[j];

//                 if (sum >= target) {
//                     res = min(res, j - i + 1);
//                     break;
//                 }
//             }
//         }
//         return (res == nums.size() + 1) ? 0 : res;
//     }
// };

// //滑动窗口
// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int left = 0, right = 0;
//         int sum = 0;
//         int res = nums.size() + 1;
//         while (right < nums.size()) {

//             sum += nums[right];
//             ++ right;

//             while (sum >= target) {
//                 if (sum >= target)
//                     res = min(res, right - left);
//                 sum -= nums[left];
//                 ++ left;
//             }

//         }
//         return (res == nums.size() + 1) ? 0 : res;
//     }
// };

//滑动窗口
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int left = 0, right = 0, sum = 0, res = nums.size() + 1;
        while (right < nums.size()) {
            sum += nums[right++];
            while (sum >= target) {
                res = min(res, right - left);
                sum -= nums[left++];
            }
        }

        return (res == nums.size() + 1) ? 0 : res;
    }
};