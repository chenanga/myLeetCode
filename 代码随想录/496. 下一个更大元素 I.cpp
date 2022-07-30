#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums2.size(); ++i)
            mp[nums2[i]] = i;

        stack<int> stc;
        vector<int> record(nums2.size(), -1);
        for (int i = 0; i < nums2.size(); ++i) {
            while (!stc.empty() && nums2[i] > nums2[stc.top()]) {
                record[stc.top()] = nums2[i];
                stc.pop();
            }
            stc.push(i);
        }

        vector<int>res(nums1.size(), 0);
        for (int i = 0; i < nums1.size(); ++i) {
            res[i] = record[mp[nums1[i]]];
        }
        return res;
    }
};

int main() {

	system("pause");
	return 0;
}