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

// // class Solution {
// // public:
// //     vector<vector<int>> threeSum(vector<int>& nums) {

// //         set<vector<int>> res;
// //         sort(nums.begin(), nums.end());

// //         for (int i = 0; i < nums.size(); ++ i) {
// //             if (nums[i] > 0) 
// //                 break;
// //             if (i > 0 && nums[i] == nums[i - 1])
// //                 continue;
// //             unordered_set<int> set;
// //             for (int j = i + 1; j < nums.size(); ++ j) {
// //                 if (set.find(-nums[i] - nums[j]) != set.end())
// //                     res.insert({nums[i], nums[j], -nums[i] - nums[j]});

// //                 set.insert(nums[j]);

// //             }
// //         }
// //         return vector<vector<int>>(res.begin(), res.end());
// //     }
// // };
// // 双指针
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> res;
//         sort(nums.begin(), nums.end());
//         for (int i = 0; i < nums.size(); ++ i) {
//             if (nums[i] > 0) break;
//             if (i > 0 && nums[i] == nums[i - 1])
//                 continue;
//             int left = i + 1, right = nums.size() - 1;
//             while (left < right) {
//                 if (right < 0) break;
//                 if (left > i + 1 && nums[left] == nums[left - 1]) {
//                     left ++;
//                     continue;  // 跳过重复的
//                 }
//                 if (right < nums.size() - 1 && nums[right] == nums[right + 1]) {
//                     right --;
//                     continue;
//                 }

//                 int sum = nums[i] + nums[left] + nums[right];
//                 if (sum == 0) {
//                     res.push_back({nums[i], nums[left], nums[right]});
//                     left ++;
//                 }
//                 else if (sum > 0)
//                     right --;
//                 else
//                     left ++;
//             }

//         }
//         return res;


//     }
// };


// 双指针
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                if (right < 0) break;


                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    res.push_back({ nums[i], nums[left], nums[right] });

                    while (right > left && nums[right] == nums[right - 1]) right--;
                    while (right > left && nums[left] == nums[left + 1]) left++;

                    // 找到答案时，双指针同时收缩
                    left++;
                    right--;
                }
                else if (sum > 0)
                    right--;
                else
                    left++;
            }

        }
        return res;


    }
};

int main() {

	system("pause");
	return 0;
}