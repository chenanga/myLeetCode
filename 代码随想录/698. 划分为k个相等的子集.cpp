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
        if (index == nums.size()) {  // ��Ϊ���k����װ��Ԫ�أ��Ҳ�����target����ôһ���ǵ���
            return true;
        }


        for (int i = 0; i < k; ++i) {
            if (i > 0 && index == 0) // ���ڵ�һ��������ŵ�ĳ��Ͱ�е�Ч������һ���ģ��������ǹ涨�ŵ���һ��Ͱ��
                break;

            if (i > 0 && record[i] == record[i - 1])  // �����ǰͱ����һ��ͯ��ͬ����ôһ��Ҳ�ǲ����Եģ����򲻻���뵽���ѭ����ֱ������
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