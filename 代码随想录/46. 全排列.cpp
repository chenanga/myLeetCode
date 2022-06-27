#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        used = vector<bool>(nums.size(), false);
        vector<int> path;
        __permute(nums, path);
        return result;
    }
private:
    vector<vector<int>> result;
    vector<bool> used;
    void __permute(vector<int>& nums, vector<int>& path) {

        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;
            used[i] = true;
            path.push_back(nums[i]);
            __permute(nums, path);
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