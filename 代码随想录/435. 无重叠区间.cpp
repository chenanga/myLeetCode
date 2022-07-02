#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int len = intervals.size();
        int end = intervals[0][1], result = 1;
        // ´Ó×óÍùÓÒ±éÀú
        for (int i = 1; i < len; ++i) {
            if (intervals[i][0] >= end) {
                end = intervals[i][1];
                result++;
            }
        }
        return len - result;
    }
private:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
};

int main() {

	system("pause");
	return 0;
}