#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//  自己想出来的贪心，但是其实不用维护begin，维护一个end就行
// class Solution {
// public:
//     int findMinArrowShots(vector<vector<int>>& points) {
//         // 可以理解为寻找交集，交集部分射出一个弓箭，该部分的气球都会爆
//         sort(points.begin(), points.end(), cmp);
//         int begin = INT_MIN, end = INT_MAX, result = 1;  // 交集为0，0
//         for (int i = 0; i < points.size(); ++ i) {
//             if (points[i][0] <= end) {  // 说明point[i]和 begin，end有交集
//                 begin = max(begin, points[i][0]);
//                 end = min(end, points[i][1]);
//             }
//             else {  // 没有交集，那么此时射箭就需要加1
//                 result ++;
//                 begin = max(INT_MIN, points[i][0]);
//                 end = min(INT_MAX, points[i][1]);
//             }
//         }

//         return result;
//     }
// private:
//     static bool cmp(const vector<int>& a, const vector<int>& b) {
//         return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
//     }
// };

// 贪心2
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // 可以理解为寻找交集，交集部分射出一个弓箭，该部分的气球都会爆
        sort(points.begin(), points.end(), cmp);
        int result = 1;  // 交集为0，0
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > points[i - 1][1])   // 说明point[i]和 point[i - 1] 不挨着
                ++result;

            else   // 挨着，更新气球右边界的最小值
                points[i][1] = min(points[i - 1][1], points[i][1]);
        }
        return result;
    }
private:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];  // 这里不用判断当第一个数字相同时候，第二个数字谁大谁小的情况，
        // 因为不管谁在前，谁在后，都会更新最小值，所以不影响，
    }
};

int main() {

	system("pause");
	return 0;
}