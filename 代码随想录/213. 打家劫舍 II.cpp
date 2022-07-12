#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        return max(tryrob(nums, 0, nums.size() - 2), tryrob(nums, 1, nums.size() - 1));
    }

private:
    // 尝试nums[start...end]
    int tryrob(vector<int>& nums, int start, int end) {
        if (start == end) return nums[start];
        vector<int> dp(end - start + 1, 0);  // 考虑偷索引前i个房屋的最大值
        // dp[i] = max(dp[i-2] + nums[i], dp[i-1])
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);

        for (int i = start + 2; i <= end; ++i) {
            dp[i - start] = max(dp[i - 2 - start] + nums[i], dp[i - 1 - start]);
        }
        return dp[end - start];
    }
};

int main() {

	system("pause");
	return 0;
}