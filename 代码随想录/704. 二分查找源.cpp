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
    int search(vector<int>& nums, int target) {

        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                right = mid - 1;
            else  // nums[mid] < target
                left = mid + 1;
        }
        return -1;
    }
};

int main() {

	system("pause");
	return 0;
}