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
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> record(26, 0);
        for (int i = 0; i < magazine.size(); ++i)
            record[magazine[i] - 'a'] ++;
        for (int i = 0; i < ransomNote.size(); ++i)
            record[ransomNote[i] - 'a'] --;

        for (int num : record) {
            if (num < 0)
                return false;
        }
        return true;
    }
};

int main() {

	system("pause");
	return 0;
}