#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        __combinationSum(candidates, target, 0, 0);
        return result;
    }
private:
    vector<vector<int>> result;
    vector<int> singleRes;
    void __combinationSum(vector<int>& candidates, int target, int sum, int start) {
        if (sum > target) return;
        if (sum == target) {
            result.push_back(singleRes);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            if (sum + candidates[i] > target) continue;
            singleRes.push_back(candidates[i]);
            __combinationSum(candidates, target, sum + candidates[i], i);
            singleRes.pop_back();
        }
        return;
    }

};

int main() {

	system("pause");
	return 0;
}