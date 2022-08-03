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

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; ++i) {
            if ((long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
                break;

            if ((long)nums[i] + nums[nums.size() - 3] + nums[nums.size() - 2] + nums[nums.size() - 1] < target)
                continue;

            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.size() - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int left = j + 1, right = nums.size() - 1;
                long long sum = nums[i] + (long long)(nums[j] - target);
                while (left < right) {

                    long long num = sum + nums[left] + nums[right];
                    if (num == 0) {
                        res.push_back({ nums[i], nums[j], nums[left], nums[right] });
                        while (left < right && nums[left] == nums[left + 1])
                            ++left;

                        while (left < right && nums[right] == nums[right - 1])
                            --right;

                        left++, right--;
                    }
                    else if (num > 0)
                        --right;
                    else
                        ++left;
                }

            }
        }
        return res;
    }
};

int main() {

	system("pause");
	return 0;
}