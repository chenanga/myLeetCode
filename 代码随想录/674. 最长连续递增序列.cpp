#include <iostream>
#include <vector>

using namespace std;

// // ��̬�滮
// class Solution {
// public:
//     int findLengthOfLCIS(vector<int>& nums) {
//         // dp[i]Ϊ��i��β�����������������
//         int len = nums.size(), res = 1;
//         vector<int> dp(len, 1);

//         for (int i = 1; i < len; ++ i) {
//             if (nums[i] > nums[i - 1])
//                 dp[i] = dp[i - 1] + 1;

//             if (res < dp[i])
//                 res = dp[i];
//         }
//         return res;
//     }
// };

// ̰��
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        // dp[i]Ϊ��i��β�����������������
        int len = nums.size(), res = 1, count = 1;

        for (int i = 1; i < len; ++i) {
            if (nums[i] > nums[i - 1])
                count++;
            else
                count = 1;
            if (res < count)
                res = count;
        }
        return res;
    }
};

int main() {

	system("pause");
	return 0;
}