#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits == "") return result;
        __letterCombinations(digits, 0, "");
        return result;
    }
private:
    vector<string> record = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    vector<string> result;
    void __letterCombinations(const string& digits, int start, const string& path) {
        if (digits.size() == path.size()) {
            result.push_back(path);
            return;
        }

        for (int i = start; i < digits.size(); ++i) {
            for (int j = 0; j < record[digits[i] - '0'].size(); ++j)
                __letterCombinations(digits, i + 1, path + record[digits[i] - '0'][j]);
        }
        return;
    }
};

int main() {

	system("pause");
	return 0;
}