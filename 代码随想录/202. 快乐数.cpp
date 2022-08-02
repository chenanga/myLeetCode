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
    bool isHappy(int n) {
        unordered_set<int> set;
        set.insert(n);
        while (1) {
            if (n == 1)
                return true;
            n = getSum(n);
            if (set.find(n) != set.end())
                return false;
            set.insert(n);
        }

        return true;
    }
private:
    int getSum(int n) {
        int sum = 0;

        while (n) {
            int temp = n % 10;
            sum += temp * temp;
            n /= 10;
        }
        return sum;
    }
};

int main() {

	system("pause");
	return 0;
}