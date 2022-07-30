#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 从右到左遍历
// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         stack<int> stc;  // 单调栈
//         vector<int> res(temperatures.size(), 0);

//         stc.push(temperatures.size() - 1);
//         for (int i = temperatures.size() - 2; i >= 0; -- i) {
//             if (temperatures[i] >= temperatures[stc.top()]) {
//                 while (!stc.empty() && temperatures[i] >= temperatures[stc.top()]) {
//                     stc.pop();
//                 }
//                 if (stc.empty())
//                     stc.push(i);
//                 else {
//                     res[i] = stc.top() - i;
//                     stc.push(i);
//                 }
//             }
//             else {
//                 res[i] = stc.top() - i;
//                 stc.push(i);
//             }

//         }

//         return res;
//     }
// };

// // 暴力超时
// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         vector<int> res(temperatures.size(), 0);
//         int max_num = 0;

//         for (int i = 0; i < temperatures.size() - 1; ++ i) {
//             for (int j = i + 1; j < temperatures.size(); ++ j) {
//                 if (temperatures[i] < temperatures[j]) {
//                     res[i] = j - i;
//                     break;
//                 }
//             }
//         }
//         return res;
//     }
// };
// // 左到右
// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         stack<int> stc;  // 单调栈
//         vector<int> res(temperatures.size(), 0);

//         stc.push(0);
//         for (int i = 1; i <temperatures.size(); ++ i) {
//             if (temperatures[i] > temperatures[stc.top()]) {
//                 while (!stc.empty() && temperatures[i] > temperatures[stc.top()]) {
//                     res[stc.top()] = i - stc.top();
//                     stc.pop();
//                 }
//                 stc.push(i);
//             }
//             else {
//                 stc.push(i);
//             }

//         }

//         return res;
//     }
// };

// 精简
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stc;  // 单调栈
        vector<int> res(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); ++i) {

            while (!stc.empty() && temperatures[i] > temperatures[stc.top()]) {
                res[stc.top()] = i - stc.top();
                stc.pop();
            }
            stc.push(i);
        }

        return res;
    }
};

int main() {

	system("pause");
	return 0;
}