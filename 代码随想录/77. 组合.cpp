#include <iostream>
#include <vector>

using namespace std;

// class Solution {
// public:
//     vector<vector<int>> combine(int n, int k) {
//         vector<int> singleRes;
//         used = vector<bool>(n,  false);
//         __combine(singleRes, n, k, 1);
//         return res;
//     }
// private:
//     vector<vector<int>> res;
//     vector<bool> used;
//     void __combine(vector<int> & vec, int n, int k, int start) {
//         // start 当前开始的位置
//         if (vec.size() == k) {
//             res.push_back(vec);
//             return;
//         }

//         for (int i = start; i <= n; ++ i) {
//             if (used[i] == false) {
//                 vec.push_back(i);
//                 used[i] = true;
//                 __combine(vec, n, k, i + 1);
//                 used[i] = false;
//                 vec.pop_back();
//             }
//         }
//         return;
//     }
// };

// 未使用used数组
// 剪枝
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> singleRes;
        __combine(singleRes, n, k, 1);
        return res;
    }
private:
    vector<vector<int>> res;
    void __combine(vector<int>& vec, int n, int k, int start) {
        // 当前位置后的元素个数全部加起来如果也不满足的话，则直接返回
        if (n - start + 1 < k - vec.size())
            return;

        // start 当前开始的位置
        if (vec.size() == k) {
            res.push_back(vec);
            return;
        }

        for (int i = start; i <= n; ++i) {

            vec.push_back(i);
            __combine(vec, n, k, i + 1);
            vec.pop_back();
        }
        return;
    }
};

int main() {

	system("pause");
	return 0;
}