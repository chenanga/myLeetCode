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
//     bool isAnagram(string s, string t) {
//         vector<int> v1(26, 0), v2(26, 0);
//         for (int i = 0; i < s.size(); ++ i)
//             v1[s[i] - 'a'] ++;
//         for (int j = 0; j < t.size(); ++ j)
//             v2[t[j] - 'a'] ++;

//         return v1 == v2;
//     }
// };

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); ++i) {
            mp[s[i]] ++;
            mp[t[i]] --;
        }
        for (auto m : mp) {
            if (m.second != 0)
                return false;
        }
        return true;
    }
};

int main() {

	system("pause");
	return 0;
}