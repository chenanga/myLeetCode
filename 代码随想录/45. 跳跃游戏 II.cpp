#include <iostream>
#include <vector>

using namespace std;

/*
这里需要统计两个覆盖范围，当前这一步的最大覆盖和下一步最大覆盖。

如果移动下标达到了当前这一步的最大覆盖最远距离了，还没有到终点的话，那么就必须再走一步来增加覆盖范围，直到覆盖范围覆盖了终点。
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int curDistance = 0, nextDistance = 0, count = 0;
        for (int i = 0; i < nums.size(); ++i) {

            nextDistance = max(nextDistance, i + nums[i]);

            // 达到了当前这一步的最大覆盖最远距离了，还没有到终点
            if (i >= curDistance && i < nums.size() - 1) {
                count++;
                curDistance = nextDistance;

                // 剪枝，如果某一部时候，下次可以到终点，那么直接return
                if (nextDistance >= nums.size() - 1)
                    return count;
            }
            else if (i >= curDistance && i == nums.size() - 1) // 达到了当前这一步的最大覆盖最远距离了，且到了终点
                return count;
        }
        return count;
    }
};

int main() {

	system("pause");
	return 0;
}