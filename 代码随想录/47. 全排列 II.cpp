#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        used = vector<bool>(nums.size(), false);
        vector<int> path;
        __permuteUnique(nums, path);
        return result;
    }
private:
    vector<vector<int>> result;
    vector<bool> used;
    void __permuteUnique(vector<int>& nums, vector<int>& path) {

        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        vector<bool> record(21, false);
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i] || record[nums[i] + 10]) continue;

            record[nums[i] + 10] = true;
            used[i] = true;
            path.push_back(nums[i]);
            __permuteUnique(nums, path);
            path.pop_back();
            used[i] = false;
        }
        return;
    }

};

int main() {

	system("pause");
	return 0;
}