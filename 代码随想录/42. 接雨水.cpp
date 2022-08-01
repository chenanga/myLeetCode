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
// ��ʱ�ˣ�320 / 322 ��ͨ����������
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int res = 0, left = 0, right = 0;  // �������������ߵ�����
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

// // ���仯 ��̬�滮
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int res = 0, record = 0;  // �������������ߵ�����
//         vector<int> left(height);
//         vector<int> right(height);
//         // ��¼ÿ����������������߶�
//         for (int i = 1; i < height.size(); ++ i)
//             left[i] = max(left[i - 1], height[i - 1]);

//         // ��¼ÿ�������ұ��������߶�
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
����ջ�ⷨ�ؼ�˼·
��Ϊһ��������ӵ����Ӹ߶ȴ���ջͷԪ���ˣ���ʱ�ͳ��ְ����ˣ�ջͷԪ�ؾ��ǰ��۵ײ������ӣ�ջͷ�ڶ���Ԫ�ؾ��ǰ�����ߵ����ӣ�����ӵ�Ԫ�ؾ��ǰ����ұߵ����ӡ�
*/

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stc;
        int res = 0;
        for (int i = 0; i < height.size(); ++i) {
            while (!stc.empty() && height[i] > height[stc.top()]) {
                int bottom = stc.top();  // �ײ��������±�
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