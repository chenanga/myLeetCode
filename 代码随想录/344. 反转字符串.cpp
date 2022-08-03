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
    void reverseString(vector<char>& s) {
        if (s.size() == 1)
            return;
        int left = 0, right = s.size() - 1;
        while (left < right) {
            swap(s[left++], s[right--]);
        }
        return;
    }
};

int main() {

	system("pause");
	return 0;
}