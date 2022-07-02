#include <iostream>
#include <vector>

using namespace std;

// // 
// class Solution {
// public:
//     vector<int> partitionLabels(string s) {
//         // 两轮循环，每记录一个字母，就判断该位置后面是否有重复出现的，如果有，则跳出循环，继续记录字母，直到后面 不再有重复出现的，此时为一个解，插入result，更新index
//         int record[26] = {0};
//         vector<int> result;
//         int index = 0;
//         for (int i = 0; i < s.size(); ++ i) {
//             record[s[i] - 'a'] ++;
//             int j = i + 1;
//             for ( ; j < s.size(); ++ j) {
//                 if (record[s[j] - 'a'] != 0)
//                     break;
//             }
//             if (j == s.size()) {
//                 // 说明后续没有出现当前的字母了，
//                 result.push_back(i - index + 1);
//                 index = i + 1;
//             }
//         }
//         return result;
//     }
// };

// 
class Solution {
public:
    vector<int> partitionLabels(string s) {
        // 两轮循环，每记录一个字母，就判断该位置后面是否有重复出现的，如果有，则跳出循环，继续记录字母，直到后面 不再有重复出现的，此时为一个解，插入result，更新index
        int record[26] = { 0 };  // 记录该字符的最远边界
        vector<int> result;
        for (int i = 0; i < s.size(); ++i)
            record[s[i] - 'a'] = i;

        int left = 0, right = 0;  // 当前字符串的最远索引
        for (int i = 0; i < s.size(); ++i) {
            right = max(right, record[s[i] - 'a']);

            if (i == right) {
                // 说明后续没有出现当前的字母了，
                result.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return result;
    }
};

int main() {

	system("pause");
	return 0;
}