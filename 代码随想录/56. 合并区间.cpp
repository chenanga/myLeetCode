#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> result;
        int left = intervals[0][0], right = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (right >= intervals[i][0]) {
                right = max(right, intervals[i][1]);  // right有可能比当前有边界还长
            }
            else {
                result.push_back({ left, right });
                left = intervals[i][0];
                right = intervals[i][1];
            }

        }

        // 记录最后一次，因为在for循环中不管咋样，都没有插入最后一个区间
        result.push_back({ left, right });
        return result;
    }


private:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
};

int main() {

	system("pause");
	return 0;
}