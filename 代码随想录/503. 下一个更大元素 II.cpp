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
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int len = nums.size();
        stack<int> stc;
        vector<int> res(len, -1);
        for (int i = 0; i < 2 * len; ++i) {
            while (!stc.empty() && nums[i % len] > nums[stc.top()]) {
                res[stc.top()] = nums[i % len];
                stc.pop();
            }
            stc.push(i % len);
        }
        return res;
    }
};

int main() {

	system("pause");
	return 0;
}