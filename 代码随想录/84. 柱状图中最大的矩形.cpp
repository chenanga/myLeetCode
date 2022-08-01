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
//     int largestRectangleArea(vector<int>& heights) {
//         int res = 0, len = heights.size();
//         vector<int> left(len, -1);  // ����ߵ�һ������С�����ӵ�����
//         vector<int> right(len, -1);  // ���ұߵ�һ������С�����ӵ�����

//         // ��¼ÿ������ ��ߵ�һ��С�ڸ����ӵ��±�
//         for (int i = 1; i < len; ++ i) {
//             int j = i - 1;
//             while (j >= 0 && heights[j] >= heights[i]) {
//                 j = left[j];
//             }
//             left[i] = j;
//         }

//         // ��¼ÿ������ �ұߵ�һ��С�ڸ����ӵ��±�
//         for (int i = len - 2; i >= 0; -- i) {
//             int j = i + 1;
//             while (j >= 0 && heights[j] >= heights[i]) {
//                 j = right[j];
//             }
//             right[i] = j;
//         }

//         for (int i = 0; i < len; ++ i) {
//             int sum = (right[i] - left[i] - 1) * heights[i];
//             res = max(res , sum);
//         }

//         return res;
//     }
// };

/*
��Ԫ�س�ջʱ��˵�������Ԫ���ǳ�ջԪ������ҵ�һ������С��Ԫ��
��Ԫ�س�ջ��˵����ջ��Ԫ���ǳ�ջԪ����ǰ�ҵ�һ������С��Ԫ��
*/
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         heights.push_back(0);
//         int res = 0, len = heights.size();
//         stack<int> stc;

//         for (int i = 0; i < len; ++ i) {
//             while (!stc.empty() && heights[i] < heights[stc.top()]) {
//                 int cur = stc.top();
//                 stc.pop();
//                 if (stc.empty())
//                     res = max(res, (i - (-1) - 1) * heights[cur]);
//                 else
//                     res = max(res, (i - stc.top() - 1) * heights[cur]);
//             }
//             stc.push(i);
//         }
//         return res;
//     }
// };

// // ����ջ�Ż�1
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         heights.insert(heights.begin(), 0);
//         heights.push_back(0);
//         int res = 0, len = heights.size();
//         stack<int> stc;

//         for (int i = 0; i < len; ++ i) {
//             while (!stc.empty() && heights[i] < heights[stc.top()]) {
//                 int cur = stc.top();
//                 stc.pop();
//                 res = max(res, (i - stc.top() - 1) * heights[cur]);
//             }
//             stc.push(i);
//         }
//         return res;
//     }
// };

// ����ջ�Ż�2
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        int res = 0, len = heights.size();
        stack<int> stc;
        stc.push(0);
        for (int i = 1; i < len; ++i) {
            while (heights[i] < heights[stc.top()]) {
                int cur = stc.top();
                stc.pop();
                res = max(res, (i - stc.top() - 1) * heights[cur]);
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