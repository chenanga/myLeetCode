#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> path;
        __subsets(nums, path, 0);
        return result;
    }
private:
    vector<vector<int>> result;

    void __subsets(vector<int>& nums, vector<int>& path, int start) {
        result.push_back(path);
        if (start >= nums.size())
            return;

        for (int i = start; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            __subsets(nums, path, i + 1);
            path.pop_back();
        }
        return;
    }
};

int main() {

	system("pause");
	return 0;
}