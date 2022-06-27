#include<iostream>
#include<vector>

using namespace std;

// class Solution {
// public:
//     int wiggleMaxLength(vector<int>& nums) {
//         int len = nums.size();
//         //��̬�滮
//         //memo[i][0] Ϊ��i��Ԫ�ؽ�β�Ľ�������ڶ����У�����ָ������һ��Ԫ�ص�Ԫ��i�ǽ���
//         //memo[i][1] Ϊ��i��Ԫ�ؽ�β����������ڶ����У�����ָ������һ��Ԫ�ص�Ԫ��i������
//         //��nums[i] > nums[i-1],����i��β�ĵĽ������е����ֵֻ������i-1��β�����ֵ
//         vector<vector<int>> memo(len, vector<int>(2, 1)); //������ʼ��

//         for (int i = 1; i < len; ++ i) {
//             if (nums[i] < nums[i - 1]) {
//                 memo[i][0] = max(memo[i - 1][1] + 1, memo[i - 1][0]);
//                 memo[i][1] = memo[i - 1][1];
//             }
//             else if (nums[i] > nums[i - 1]) {
//                 memo[i][0] = memo[i - 1][0];
//                 memo[i][1] = max(memo[i - 1][0] + 1, memo[i - 1][1]);
//             }
//             else { //nums[i] == nums[i - 1]
//                 memo[i][0] = memo[i - 1][0];
//                 memo[i][1] = memo[i - 1][1];
//             }
//         }
//         return max(memo[len - 1][0], memo[len - 1][1]);
//     }
// };

// //ʹ�ù�������1
// class Solution {
// public:
//     int wiggleMaxLength(vector<int>& nums) {
//         int len = nums.size();
//         //��̬�滮
//         //memo[i][0] Ϊ��i��Ԫ�ؽ�β�Ľ�������ڶ����У�����ָ������һ��Ԫ�ص�Ԫ��i�ǽ���
//         //memo[i][1] Ϊ��i��Ԫ�ؽ�β����������ڶ����У�����ָ������һ��Ԫ�ص�Ԫ��i������
//         //��nums[i] > nums[i-1],����i��β�ĵĽ������е����ֵֻ������i-1��β�����ֵ
//         int preUp = 1, preDown = 1;
//         int curUp = 1, curDown = 1;

//         for (int i = 1; i < len; ++ i) {
//             if (nums[i] < nums[i - 1]) {
//                 curDown = max(preUp + 1, preDown);
//                 curUp = preUp;
//             }
//             else if (nums[i] > nums[i - 1]) {
//                 curUp = max(preDown + 1, preUp);
//                 curDown = preDown;

//             }
//             else { //nums[i] == nums[i - 1]
//                 curDown = preDown;
//                 curUp = preUp;
//             }
//             preDown = curDown;
//             preUp = curUp;
//         }
//         return max(preDown, preUp);
//     }
// };

//ʹ�ù�������2
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();
        //��̬�滮
        //memo[i][0] Ϊ��i��Ԫ�ؽ�β�Ľ�������ڶ����У�����ָ������һ��Ԫ�ص�Ԫ��i�ǽ���
        //memo[i][1] Ϊ��i��Ԫ�ؽ�β����������ڶ����У�����ָ������һ��Ԫ�ص�Ԫ��i������
        //��nums[i] > nums[i-1],����i��β�ĵĽ������е����ֵֻ������i-1��β�����ֵ
        int preUp = 1, preDown = 1;

        for (int i = 1; i < len; ++i) {
            if (nums[i] < nums[i - 1])
                preDown = max(preUp + 1, preDown);

            else if (nums[i] > nums[i - 1])
                preUp = max(preDown + 1, preUp);

        }
        return max(preDown, preUp);
    }
};

int main() {

	system("pause");
	return 0;
}