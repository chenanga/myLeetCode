#include <iostream>
#include <vector>

using namespace std;

/*
其实跳几步无所谓，关键在于可跳的覆盖范围！
不一定非要明确一次究竟跳几步，每次取最大的跳跃步数，这个就是可以跳跃的覆盖范围。
这个范围内，别管是怎么跳的，反正一定可以跳过来。
那么这个问题就转化为跳跃覆盖范围究竟可不可以覆盖到终点！
每次移动取最大跳跃步数（得到最大的覆盖范围），每移动一个单位，就更新最大覆盖范围。
贪心算法局部最优解：每次取最大跳跃步数（取最大覆盖范围），整体最优解：最后得到整体最大覆盖范围，看是否能到终点。
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int index = 0;
        for (int i = 0; i <= index; ++i) {
            index = max(index, i + nums[i]);
            if (index >= nums.size() - 1)
                return true;
        }
        return false;
    }
};

int main() {

	system("pause");
	return 0;
}