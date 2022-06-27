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
//         sort(nums.begin(), nums.end()); //�����򣬱�������ظ�Ԫ��

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

//         vector<bool>used(21, false); //-10 --- 10  21������
//         for(int i = start; i < nums.size(); i ++){
//             if(!used[ nums[i] + 10 ]){
//                 p.push_back(nums[i]);
//                 used[ nums[i] + 10] = true;
//                 generateSubsetsWithDup(nums, i + 1, p);
//                 p.pop_back(); //��Ҫ����һ��֮ǰҪ�ѵ�ǰ�����pop��
//             }
//         }
//         return ;
//     }
// };

int main() {

	system("pause");
	return 0;
}