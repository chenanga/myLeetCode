#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//  �Լ��������̰�ģ�������ʵ����ά��begin��ά��һ��end����
// class Solution {
// public:
//     int findMinArrowShots(vector<vector<int>>& points) {
//         // �������ΪѰ�ҽ����������������һ���������ò��ֵ����򶼻ᱬ
//         sort(points.begin(), points.end(), cmp);
//         int begin = INT_MIN, end = INT_MAX, result = 1;  // ����Ϊ0��0
//         for (int i = 0; i < points.size(); ++ i) {
//             if (points[i][0] <= end) {  // ˵��point[i]�� begin��end�н���
//                 begin = max(begin, points[i][0]);
//                 end = min(end, points[i][1]);
//             }
//             else {  // û�н�������ô��ʱ�������Ҫ��1
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

// ̰��2
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // �������ΪѰ�ҽ����������������һ���������ò��ֵ����򶼻ᱬ
        sort(points.begin(), points.end(), cmp);
        int result = 1;  // ����Ϊ0��0
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > points[i - 1][1])   // ˵��point[i]�� point[i - 1] ������
                ++result;

            else   // ���ţ����������ұ߽����Сֵ
                points[i][1] = min(points[i - 1][1], points[i][1]);
        }
        return result;
    }
private:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];  // ���ﲻ���жϵ���һ��������ͬʱ�򣬵ڶ�������˭��˭С�������
        // ��Ϊ����˭��ǰ��˭�ں󣬶��������Сֵ�����Բ�Ӱ�죬
    }
};

int main() {

	system("pause");
	return 0;
}