#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> path;
        __subsetsWithDup(nums, path, 0);
        return result;
    }
private:
    vector<vector<int>> result;
    void __subsetsWithDup(vector<int>& nums, vector<int>& path, int start) {
        result.push_back(path);
        if (start >= nums.size())
            return;

        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i - 1])
                continue;
            path.push_back(nums[i]);
            __subsetsWithDup(nums, path, i + 1);
            path.pop_back();

        }
        return;

    }
};

// class Solution {
// public:
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         sort(nums.begin(), nums.end()); //先排序，避免出现重复元素

//         vector<int>p;
//         generateSubsetsWithDup(nums, 0, p);
//         return res;
//     }
// private:
//     vector<vector<int>> res;
//     void generateSubsetsWithDup(vector<int>& nums, int start, vector<int>& p){
//         res.push_back(p);
//         if(start == nums.size())
//             return;

//         vector<bool>used(21, false); //-10 --- 10  21个数字
//         for(int i = start; i < nums.size(); i ++){
//             if(!used[ nums[i] + 10 ]){
//                 p.push_back(nums[i]);
//                 used[ nums[i] + 10] = true;
//                 generateSubsetsWithDup(nums, i + 1, p);
//                 p.pop_back(); //重要，下一轮之前要把当前加入的pop掉
//             }
//         }
//         return ;
//     }
// };

int main() {

	system("pause");
	return 0;
}