#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int result = 0;
        vector<int> record(n, 1);  // 初始化=每人一个

        // 一次是从左到右遍历，只比较右边孩子评分比左边大的情况。
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1])
                record[i] = record[i - 1] + 1;

        }

        // 一次是从右到左遍历，只比较左边孩子评分比右边大的情况。
        /*
局部最优：取record[i + 1] + 1 和 record[i] 最大的糖果数量，保证第i个小孩的糖果数量即大于左边的也大于右边的。
全局最优：相邻的孩子中，评分高的孩子获得更多的糖果。
        */
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1])
                record[i] = max(record[i], record[i + 1] + 1);
            result += record[i];
        }
        return result + record[n - 1];
    }
};

int main() {

	system("pause");
	return 0;
}