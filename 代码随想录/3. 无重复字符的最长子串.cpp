#include "general.h"

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         if (s.empty())
//             return 0;
//         unordered_set<char> set;
//         int ans = 0, right = 0;
//         // [i...right)
//         for (int i = 0; i < s.size(); ++ i) {
//             if (i != 0) 
//                 set.erase(s[i - 1]);
//             while (right < s.size() && set.find(s[right]) == set.end()) {
//                 set.insert(s[right]);
//                 ++ right;
//             }
//             ans = max(ans, right - i);  // right - i = right - 1 - i + 1
//         }
//         return ans;
//     }
// };

// 记录一下上次的位置
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int record[256] = { 0 };
        int left = 0, ans = 0;
        // s[left...i]
        for (int i = 0; i < s.size(); ++i) {
            left = max(left, record[s[i]]);
            record[s[i]] = i + 1;
            ans = max(ans, i - left + 1);

        }
        return ans;
    }
};