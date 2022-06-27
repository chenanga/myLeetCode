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
//         // start ��ǰ��ʼ��λ��
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

// δʹ��used����
// ��֦
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
        // ��ǰλ�ú��Ԫ�ظ���ȫ�����������Ҳ������Ļ�����ֱ�ӷ���
        if (n - start + 1 < k - vec.size())
            return;

        // start ��ǰ��ʼ��λ��
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