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

// class Solution {
// public:
//     string replaceSpace(string s) {
//         string res;
//         for (int i = 0; i < s.size(); ++ i) {
//             if (s[i] == ' ')
//                 res += "%20";
//             else
//                 res.push_back(s[i]);
//         }
//         return res;
//     }
// };

// 不使用额外空间
class Solution {
public:
    string replaceSpace(string s) {
        int count = 0, i = s.size() - 1;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ')
                ++count;
        }
        s.resize(s.size() + 2 * count);

        int j = s.size() - 1;
        while (i >= 0) {
            if (s[i] == ' ') {
                s[j--] = '0';
                s[j--] = '2';
                s[j--] = '%';
                --i;
            }
            else {
                s[j--] = s[i--];
            }

        }
        return s;
    }
};

int main() {

	system("pause");
	return 0;
}