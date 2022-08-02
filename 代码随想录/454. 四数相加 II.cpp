#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <algorithm>
#include <deque>
#include <queue>

using namespace std;

// ��ʱ
// class Solution {
// public:
//     int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
//         int n = nums1.size(), res = 0;
//         unordered_map<int, int> mp;  // key: ֵ, value: ����
//         for (int i = 0; i < n; ++ i)
//             mp[nums4[i]] ++;

//         for (int i = 0; i < n; ++ i) {
//             for (int j = 0; j < n; ++ j) {
//                 for (int k = 0; k < n; ++ k) {
//                     res += mp[-nums1[i] - nums2[j] - nums3[k]];
//                 }
//             }
//         }
//         return res;
//     }
// };

// ������ѭ�����Ϊ��������ѭ��
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size(), res = 0;
        unordered_map<int, int> mp;  // key: ֵ, value: ����
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                mp[nums3[i] + nums4[j]] ++;
            }
        }


        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                res += mp[-nums1[i] - nums2[j]];
            }
        }
        return res;
    }
};

int main() {

	system("pause");
	return 0;
}