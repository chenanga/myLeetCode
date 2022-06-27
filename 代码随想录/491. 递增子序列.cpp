#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> path;  // 存放每次的答案
        __findSubsequences(nums, path, 0);
        return result;
    }
private:
    vector<vector<int>> result;   // 存放最终的答案
    void __findSubsequences(vector<int>& nums, vector<int>& path, int start) {

        // 保证长度为2或以上
        if (path.size() >= 2)
            result.push_back(path);

        // 递归终止条件
        if (start == nums.size())
            return;

        vector<int> used(201, false);
        for (int i = start; i < nums.size(); ++i) {
            if (used[nums[i] + 100]) // 如果当前位置的元素值已经使用过，则进入下一次循环，跳过该数
                continue;
            if (path.empty()) { // 如果path为空，则直接插入当前元素
                used[nums[i] + 100] = true;
                path.push_back(nums[i]);
                __findSubsequences(nums, path, i + 1);
                path.pop_back();
            }
            else { // path不为空
                if (nums[i] >= path.back()) {  // 判断当前元素是否大于等于path 的最后一个元素
                    used[nums[i] + 100] = true;
                    path.push_back(nums[i]);
                    __findSubsequences(nums, path, i + 1);
                    path.pop_back();
                }
            }
        }
        return;
    }
};

int main() {

	system("pause");
	return 0;
}