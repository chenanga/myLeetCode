#include "general.h"

// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         // ά��һ���󶥶�
//         map<int, int, greater<int>> mp; 
//         int len = nums.size();
//         vector<int> res(len -k + 1, 0);
//         for (int i = 0; i < k; ++ i) 
//             mp[nums[i]] ++;

//         // ������������Ϊnums[i, k + i - 1]
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

// ʹ��һ�����ȶ���
// ������pair��firstΪֵ��secondΪ����
// ����ѭ����һ�Σ�����res0Ҫ�ȸ�ֵ
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         // ά��һ���󶥶�
//         priority_queue<pair<int, int>> bigHeap;
//         int len = nums.size();
//         vector<int> res(len -k + 1, 0);
//         for (int i = 0; i < k; ++ i) 
//             bigHeap.push(pair<int, int>(nums[i], i));
//         res[0] = bigHeap.top().first;

//         // ������������Ϊnums[i, k + i - 1]
//         for (int i = k; i < len ; ++ i) {

//             bigHeap.push(pair<int, int>(nums[i], i));

//             while (bigHeap.top().second <= i - k)
//                 bigHeap.pop();

//             res[i - k + 1] = bigHeap.top().first;

//         }
//         return res;
//     }
// };

// // ʹ��һ�����д洢���л�û�б��Ƴ����±�
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         // ά��һ���󶥶�
//         deque<int> deq;
//         int len = nums.size();
//         vector<int> res(len -k + 1, 0);

//         for (int i = 0; i < k ; ++ i) {

//             while (!deq.empty() && nums[i] >= nums[deq.back()])
//                 deq.pop_back();
//             deq.push_back(i);
//         }

//         // ������������Ϊnums[i, k + i - 1]
//         for (int i = 0; i < len - k + 1; ++ i) {

//             res[i] = nums[deq.front()];

//             // ���￪ʼ�Ǵ�����һ������
//             if (i + k < len) {
//                 while (!deq.empty() && nums[i + k] >= nums[deq.back()])
//                     deq.pop_back();
//                 deq.push_back(i + k);
//             }

//             // ������Ҫ�жϵ���i���������Ϊ��ʱi�����ڻ������ڵĲ���
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
        deque<int> deq;  // ����±�

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