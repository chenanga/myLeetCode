#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// // 动态规划
// /*
// 转换为背包问题，wordDict是物品，可以任意选取，s为背包容量，看是否有一种组合，刚好等于s
// */
// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         int len = s.size();
//         vector<bool> dp(len + 1, false); // dp[i] 是否能用worddict表示s前i个字符
//         dp[0] = true;
//         for (int i = 1; i <= len; ++ i) {
//             for (int j = 0; j < wordDict.size(); ++ j) {
//                 if (i >= wordDict[j].size())
//                     dp[i] = dp[i] || (dp[i - wordDict[j].size()] && isSame(s, i - wordDict[j].size(), i,  wordDict[j]));

//             }
//         }

//         return dp[len];
//     }
// private:
//     bool isSame(const string& s1, int start, int end, const string& s2) {
//         for (int i = start, j = 0; i < end; ++ i, j ++) {
//             if (s1[i] != s2[j])
//                 return false;
//         }
//         return true;
//     }

// };


// 动态规划,字符串判断优化,使用一个哈希set存储，用来判断是否存在
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        unordered_set<string> record(wordDict.begin(), wordDict.end());
        vector<bool> dp(len + 1, false); // dp[i] 是否能用worddict表示s前i个字符
        dp[0] = true;
        for (int i = 1; i <= len; ++i) {
            for (int j = 0; j < wordDict.size(); ++j) {

                if (i >= wordDict[j].size()) {
                    string word = s.substr(i - wordDict[j].size(), wordDict[j].size());

                    dp[i] = dp[i] || (dp[i - wordDict[j].size()] && record.find(word) != record.end());
                }

            }
        }

        return dp[len];
    }


};

int main() {

	system("pause");
	return 0;
}