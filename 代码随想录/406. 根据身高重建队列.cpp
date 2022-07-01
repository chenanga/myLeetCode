#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

// 按照身高升序排列，然后相同身高的按照第二个数降序
// struct cmp {
//     bool operator()(vector<int> v1, vector<int> v2) {
//         return v1[0] < v2[0] || (v1[0] == v2[0] && v1[1] > v2[1]);
//     }
// };
// class Solution {
// public:
//     vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
//         sort(people.begin(), people.end(), cmp());
//         vector<vector<int>> res(people.size(), vector<int>(2, -1));

//         for (const vector<int> & vec : people) {
//             int space = 0;
//             for (int i = 0; i < people.size(); ++ i) {
//                 if (res[i][0] == -1)
//                     ++ space;
//                 if (space == vec[1] + 1) {
//                     res[i] = vec;
//                     break;
//                 }
//             }
//         }

//         return res;
//     }
// };

// 贪心策略
static bool cmp(const vector<int>& a, const vector<int>& b) {
    if (a[0] == b[0])
        return a[1] < b[1];
    return a[0] > b[0];
}

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);

        list<vector<int>> result;

        for (int i = 0; i < people.size(); ++i) {
            int pos = people[i][1];
            list<vector<int>>::iterator iter = result.begin();
            while (pos > 0) {
                ++iter;
                --pos;
            }
            result.insert(iter, people[i]);
        }
        return vector<vector<int>>(result.begin(), result.end());
    }
};




int main() {

	system("pause");
	return 0;
}