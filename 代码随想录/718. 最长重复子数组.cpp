#include <iostream>
#include <vector>

using namespace std;
// ������Ĭ�ϲ�������������Ĭ������
/*
dp[i][j] �����±�i - 1Ϊ��β��A�������±�j - 1Ϊ��β��B����ظ������鳤��Ϊdp[i][j]��
*/
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size(), result = 0;
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        // if (nums1[i] == nums2[j]) dp[i][j] = dp[i-1][j-1] + 1;

        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > result)
                    result = dp[i][j];

            }
        }

        return result;
    }
};


int main() {

	system("pause");
	return 0;
}