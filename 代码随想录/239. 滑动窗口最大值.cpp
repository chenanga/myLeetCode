#include "general.h"

// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         // 维护一个大顶堆
//         map<int, int, greater<int>> mp; 
//         int len = nums.size();
//         vector<int> res(len -k + 1, 0);
//         for (int i = 0; i < k; ++ i) 
//             mp[nums[i]] ++;

//         // 滑动窗口区间为nums[i, k + i - 1]
//         for (int i = 0; i < len - k + 1; ++ i) {
//             res[i] = mp.begin()->first;
//             // cout << "res[" << i << "] = " << res[i] << endl;
//             mp[nums[i]] --;
//             if (mp[nums[i]] == 0)
//                 mp.erase(nums[i]);

//             // cout << "res[" << i << "] = " << res[i] << endl;

//             if (k + i < len)
//                 mp[nums[k + i]] ++;
//         }
//         return res;
//     }
// };

// 使用一个优先队列
// 里面存放pair，first为值，second为索引
// 这里循环少一次，所以res0要先赋值
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         // 维护一个大顶堆
//         priority_queue<pair<int, int>> bigHeap;
//         int len = nums.size();
//         vector<int> res(len -k + 1, 0);
//         for (int i = 0; i < k; ++ i) 
//             bigHeap.push(pair<int, int>(nums[i], i));
//         res[0] = bigHeap.top().first;

//         // 滑动窗口区间为nums[i, k + i - 1]
//         for (int i = k; i < len ; ++ i) {

//             bigHeap.push(pair<int, int>(nums[i], i));

//             while (bigHeap.top().second <= i - k)
//                 bigHeap.pop();

//             res[i - k + 1] = bigHeap.top().first;

//         }
//         return res;
//     }
// };

// // 使用一个队列存储所有还没有被移除的下标
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         // 维护一个大顶堆
//         deque<int> deq;
//         int len = nums.size();
//         vector<int> res(len -k + 1, 0);

//         for (int i = 0; i < k ; ++ i) {

//             while (!deq.empty() && nums[i] >= nums[deq.back()])
//                 deq.pop_back();
//             deq.push_back(i);
//         }

//         // 滑动窗口区间为nums[i, k + i - 1]
//         for (int i = 0; i < len - k + 1; ++ i) {

//             res[i] = nums[deq.front()];

//             // 这里开始是处理下一个窗口
//             if (i + k < len) {
//                 while (!deq.empty() && nums[i + k] >= nums[deq.back()])
//                     deq.pop_back();
//                 deq.push_back(i + k);
//             }

//             // 这里需要判断等于i的情况，因为此时i不属于滑动窗口的部分
//             while (!deq.empty() && deq.front() <= i)
//                 deq.pop_front();


//         }

//         return res;
//     }
// };



class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> deq;  // 存放下标

        for (int i = 0; i < k; ++i) {
            while (!deq.empty() && nums[i] >= nums[deq.back()]) {
                deq.pop_back();
            }
            deq.push_back(i);
        }

        vector<int> res;
        res.push_back(nums[deq.front()]);
        for (int i = k; i < n; ++i) {
            if (i - k == deq.front())
                deq.pop_front();
            while (!deq.empty() && nums[i] >= nums[deq.back()]) {
                deq.pop_back();
            }
            deq.push_back(i);
            res.push_back(nums[deq.front()]);
        }
        return res;

    }
};