#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        //  分析：1+2+...+9 = 45
        //根据题意，最多只能表示3---45,也就是n超过该范围，无解 
        if (n < 3 || n > 45)
            return result;
        __combinationSum3(k, n, 1, 0);
        return result;
    }

private:
    vector<vector<int>> result;
    vector<int> path;
    void __combinationSum3(int k, int n, int start, int sum) {
        // 剪枝
        if (sum > n || (path.size() == k && sum != n)) return;
        if (sum == n && path.size() == k) {
            result.push_back(path);
            return;
        }

        for (int i = start; i <= 9; ++i) {
            path.push_back(i);
            __combinationSum3(k, n, i + 1, sum + i);
            path.pop_back();
        }
        return;
    }
};

int main() {

	system("pause");
	return 0;
}