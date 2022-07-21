#include <iostream>
#include <vector>

using namespace std;

/*
直线不能相交，这就是说明在字符串A中 找到一个与字符串B相同的子序列，且这个子序列不能改变相对顺序，只要相对顺序不改变，链接相同数字的直线就不会相交。
*/
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        // dp[i][j] 代表nums1中 i-1结尾的和nums2中j-1结尾的最大连线数

        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[len1][len2];
    }
};

int main() {

	system("pause");
	return 0;
}