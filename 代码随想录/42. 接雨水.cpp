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

// #include <bits/stdc++.h>
// 超时了，320 / 322 个通过测试用例
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int res = 0, left = 0, right = 0;  // 代表该列左右最高的柱子
//         for (int i = 0; i < height.size(); ++ i) {
//             left = height[i], right = height[i];
//             if (i == 0 || i == height.size() - 1)
//                 continue;
//             for (int j = i - 1; j >= 0; -- j) {
//                 if (height[j] > left)
//                     left = height[j];
//             }
//             for (int j = i + 1; j < height.size(); ++ j) {
//                 if (height[j] > right)
//                     right = height[j];
//             }
//             res += min(left, right) - height[i];

//         }
//         return res;

//     }
// };

// // 记忆化 动态规划
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int res = 0, record = 0;  // 代表该列左右最高的柱子
//         vector<int> left(height);
//         vector<int> right(height);
//         // 记录每个柱子左边柱子最大高度
//         for (int i = 1; i < height.size(); ++ i)
//             left[i] = max(left[i - 1], height[i - 1]);

//         // 记录每个柱子右边柱子最大高度
//         for (int i = height.size() - 2; i >= 0; -- i)
//             right[i] = max(right[i + 1], height[i + 1]);

//         for (int i = 0; i < height.size(); ++ i) {
//             if (i == 0 || i == height.size() - 1)
//                 continue;
//             int sum = min(left[i], right[i]) - height[i];
//             if (sum > 0)
//                 res += sum;
//         }
//         return res;

//     }
// };

/*
单调栈解法关键思路
因为一旦发现添加的柱子高度大于栈头元素了，此时就出现凹槽了，栈头元素就是凹槽底部的柱子，栈头第二个元素就是凹槽左边的柱子，而添加的元素就是凹槽右边的柱子。
*/

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stc;
        int res = 0;
        for (int i = 0; i < height.size(); ++i) {
            while (!stc.empty() && height[i] > height[stc.top()]) {
                int bottom = stc.top();  // 底部的索引下标
                stc.pop();
                if (stc.empty())
                    break;

                // h = min(height[stc.top()], height[i]) - height[bottom]
                // w = i - stc.top() - 1
                res += (min(height[stc.top()], height[i]) - height[bottom]) * (i - stc.top() - 1);
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