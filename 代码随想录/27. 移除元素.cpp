#include "general.h"

// //ά��һ����Χ���÷�Χ��Ҫ��ӡ��[0...index]��ÿ����������val�ģ���index�Ľ�����������index--
// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {
//         int i = 0, end = nums.size() - 1;
//         // ������Ҫ�������ǡ�0��index��
//         while (i <= end) {
//             if (nums[i] == val) 
//                 swap(nums[i], nums[end--]);
//             else
//                 ++ i;
//         }
//         return end + 1;
//     }
// };


// ˫ָ��, û�иı�Ԫ�ص����λ��
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0, fast = 0;
        // ������Ҫ�������ǡ�0��slow)
        while (fast < nums.size()) {
            if (nums[fast] != val)
                swap(nums[fast++], nums[slow++]);
            else
                ++fast;
        }
        return slow;
    }
};