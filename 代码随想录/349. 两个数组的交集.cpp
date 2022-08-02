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

// class Solution {
// public:
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//         vector<bool> record(1001, false);
//         vector<int> res;
//         for (int i = 0; i < nums1.size(); ++ i)
//             record[nums1[i]]  = true;

//         for (int i = 0; i < nums2.size(); ++ i) {
//             if (record[nums2[i]]) {
//                 record[nums2[i]] = false;  // 去重
//                 res.emplace_back(nums2[i]);
//             }
//         }
//         return res;
//     }
// };


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool> mp;
        vector<int> res;
        for (int i = 0; i < nums1.size(); ++i)
            mp[nums1[i]] = true;

        for (int i = 0; i < nums2.size(); ++i) {
            if (mp[nums2[i]]) {
                mp[nums2[i]] = false;  // 去重
                res.emplace_back(nums2[i]);
            }
        }
        return res;
    }
};

int main() {

	system("pause");
	return 0;
}