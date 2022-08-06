#include "general.h"

// class Solution {
// public:
//     string reverseLeftWords(string s, int n) {
//         if (n > s.size())
//             n = n % s.size();

//         string res;
//         for (int i = n; i < s.size(); ++ i) {
//             res.push_back(s[i]);
//         }
//         for (int i = 0; i < n; ++ i)
//             res.push_back(s[i]);

//         return res;
//     }
// };

// 不使用额外空间
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        if (n > s.size())
            n = n % s.size();
        int left = 0, right = s.size() - 1;
        while (left < right)
            swap(s[left++], s[right--]);

        left = 0, right = s.size() - 1 - n;
        while (left < right)
            swap(s[left++], s[right--]);

        left = s.size() - n, right = s.size() - 1;
        while (left < right)
            swap(s[left++], s[right--]);

        return s;
    }
};