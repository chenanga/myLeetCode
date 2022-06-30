#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


// // 模拟
// class Solution {
// public:
//     int largestSumAfterKNegations(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end());
//         int sum = accumulate(nums.begin(), nums.end(), 0);
//         if (nums[0] >= 0) {
//             if (k % 2 == 0)
//                 return sum;
//             else
//                 return sum - 2 * nums[0];
//         }
//         else if (nums[nums.size() - 1] <= 0) {

//             // 全是负的
//             if (k == nums.size()) {

//                 return - sum;
//             }
//             else if (k < nums.size()) {

//                 int temp = 0;
//                 for (int j = 0; j < k; ++ j)
//                     temp += nums[j];
//                 return sum - 2 * temp;
//             }
//             else {  // k > nums.size()
//                 if ((k - nums.size()) % 2 == 0) {
//                     return - sum;
//                 }
//                 else 
//                     return - sum + 2 * nums[nums.size() - 1];
//             }
//         }
//         else {
//             // 遍历找到第一个大于等于0的位置，然后
//             int i = 1;
//             for ( ; i < nums.size(); ++ i) {
//                 if (nums[i] >= 0)
//                     break;
//             }
//             // nums[0,i - 1] 为负数， 共有i个数字
//             // 如果 k == i, 把前i个都替换为正数(把前k个替换为正数)
//             // 如果 k < i , 把前k个替换为正数
//             // 故，以上两种情况可以合并
//             // 如果 k > i, 
//             //           如果(k - i) % 2 == 0, 能把前i个都替换为正数
//             //              如果(k - i) % 2 == 1 , 把前i个替换为正数，再选择一个和0最接近的值变为负数
//             if (k <= i) {
//                 int temp = 0;
//                 for (int j = 0; j < k; ++ j)
//                     temp += nums[j];
//                 return sum - 2 * temp;
//             }
//             else {  // k > i
//                 int temp = 0;
//                 for (int j = 0; j < i; ++ j)
//                     temp += nums[j];

//                 if ((k - i) % 2 == 0)
//                     return sum - 2 * temp;
//                 else {
//                     int minNum = min(- nums[i - 1], nums[i]);
//                     return sum - 2 * temp - 2 * minNum;

//                 }

//             }
//         }
//         return -1;
//     }
// };

// 贪心
/*
第一步：将数组按照绝对值大小从大到小排序，注意要按照绝对值的大小
第二步：从前向后遍历，遇到负数将其变为正数，同时K--
第三步：如果K还大于0，那么反复转变数值最小的元素，将K用完
第四步：求和
*/
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {

        // 1.按照绝对值从大到小排序
        sort(nums.begin(), nums.end(), cmp);
        for (int i = 0; i < nums.size(); ++i) {
            // 遇到负数，变为正，然后k--
            if (nums[i] < 0 && k > 0) {
                nums[i] = -nums[i];
                k--;
            }
        }

        if (k % 2 == 1)  // 如果此时k不为0, 把最后一个变为负
            nums[nums.size() - 1] = -nums[nums.size() - 1];

        return accumulate(nums.begin(), nums.end(), 0);
    }
private:
    static bool cmp(int a, int b) {
        return abs(a) > abs(b);
    }
};

int main() {

	vector<int> vec;
	int num, k;
	while (cin >> num) {
		vec.push_back(num);
		char ch = getchar();//读取下一个字符，为换行符，则break
		if (ch == '\n')
			break;
	}

	cin >> k;

	cout << Solution().largestSumAfterKNegations(vec, k) << endl;
			

	system("pause");
	return 0;
}