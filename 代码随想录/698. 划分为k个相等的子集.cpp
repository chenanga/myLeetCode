#include "general.h"

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (k > nums.size())
            return false;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
            sum += nums[i];

        if (sum % k != 0)
            return false;
        target = sum / k;
        used = vector<bool>(nums.size(), false);
        record = vector<int>(k, 0);
        sort(nums.begin(), nums.end(), greater<int>());
        return __canPartitionKSubsets(nums, k, 0);


    }
private:
    vector<bool> used;
    vector<int> record;
    int target;
    bool __canPartitionKSubsets(vector<int>& nums, int k, int index) {
        if (index == nums.size()) {  // 因为如果k个都装入元素，且不大于target，那么一定是等于
            return true;
        }


        for (int i = 0; i < k; ++i) {
            if (i > 0 && index == 0) // 对于第一个球，任意放到某个桶中的效果都是一样的，所以我们规定放到第一个桶中
                break;

            if (i > 0 && record[i] == record[i - 1])  // 如果当前捅和上一个童相同，那么一定也是不可以的，否则不会进入到这次循环，直接跳过
                continue;
            if (record[i] + nums[index] > target) {
                // if (record[i] < target)
                //     break;
                continue;
            }

            record[i] += nums[index];
            if (__canPartitionKSubsets(nums, k, index + 1))
                return true;
            record[i] -= nums[index];

        }

        return false;

    }
};