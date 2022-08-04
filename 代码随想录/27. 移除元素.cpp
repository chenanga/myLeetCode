#include "general.h"

// //维护一个范围，该范围是要打印的[0...index]，每当遇到等于val的，和index的交换，交换完index--
// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {
//         int i = 0, end = nums.size() - 1;
//         // 最终需要的区间是【0，index】
//         while (i <= end) {
//             if (nums[i] == val) 
//                 swap(nums[i], nums[end--]);
//             else
//                 ++ i;
//         }
//         return end + 1;
//     }
// };


// 双指针, 没有改变元素的相对位置
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0, fast = 0;
        // 最终需要的区间是【0，slow)
        while (fast < nums.size()) {
            if (nums[fast] != val)
                swap(nums[fast++], nums[slow++]);
            else
                ++fast;
        }
        return slow;
    }
};