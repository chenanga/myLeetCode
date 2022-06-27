#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        __partition(s, 0);
        return result;
    }
private:
    vector<vector<string>> result;
    vector<string> path;
    void __partition(const string& s, int start) {
        if (start >= s.size()) {
            result.emplace_back(path);
            return;
        }

        for (int i = start; i < s.size(); ++i) {
            string str = s.substr(start, i - start + 1);
            if (isHuiWen(str)) {
                path.emplace_back(str);
                __partition(s, i + 1);
                path.pop_back();
            }
        }
        return;
    }


    bool isHuiWen(const string& str) {
        if (str.size() <= 0) return false;
        int left = 0, right = str.size() - 1;

        while (left < right) {
            if (str[left] == str[right]) {
                ++left;
                --right;
            }
            else
                break;
        }

        return left >= right ? true : false;
    }
};

int main() {

	system("pause");
	return 0;
}