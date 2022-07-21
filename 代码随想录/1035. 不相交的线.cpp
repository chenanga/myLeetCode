#include <iostream>
#include <vector>

using namespace std;

/*
ֱ�߲����ཻ�������˵�����ַ���A�� �ҵ�һ�����ַ���B��ͬ�������У�����������в��ܸı����˳��ֻҪ���˳�򲻸ı䣬������ͬ���ֵ�ֱ�߾Ͳ����ཻ��
*/
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        // dp[i][j] ����nums1�� i-1��β�ĺ�nums2��j-1��β�����������

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