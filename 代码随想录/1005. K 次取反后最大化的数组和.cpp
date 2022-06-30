#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


// // ģ��
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

//             // ȫ�Ǹ���
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
//             // �����ҵ���һ�����ڵ���0��λ�ã�Ȼ��
//             int i = 1;
//             for ( ; i < nums.size(); ++ i) {
//                 if (nums[i] >= 0)
//                     break;
//             }
//             // nums[0,i - 1] Ϊ������ ����i������
//             // ��� k == i, ��ǰi�����滻Ϊ����(��ǰk���滻Ϊ����)
//             // ��� k < i , ��ǰk���滻Ϊ����
//             // �ʣ���������������Ժϲ�
//             // ��� k > i, 
//             //           ���(k - i) % 2 == 0, �ܰ�ǰi�����滻Ϊ����
//             //              ���(k - i) % 2 == 1 , ��ǰi���滻Ϊ��������ѡ��һ����0��ӽ���ֵ��Ϊ����
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

// ̰��
/*
��һ���������鰴�վ���ֵ��С�Ӵ�С����ע��Ҫ���վ���ֵ�Ĵ�С
�ڶ�������ǰ���������������������Ϊ������ͬʱK--
�����������K������0����ô����ת����ֵ��С��Ԫ�أ���K����
���Ĳ������
*/
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {

        // 1.���վ���ֵ�Ӵ�С����
        sort(nums.begin(), nums.end(), cmp);
        for (int i = 0; i < nums.size(); ++i) {
            // ������������Ϊ����Ȼ��k--
            if (nums[i] < 0 && k > 0) {
                nums[i] = -nums[i];
                k--;
            }
        }

        if (k % 2 == 1)  // �����ʱk��Ϊ0, �����һ����Ϊ��
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
		char ch = getchar();//��ȡ��һ���ַ���Ϊ���з�����break
		if (ch == '\n')
			break;
	}

	cin >> k;

	cout << Solution().largestSumAfterKNegations(vec, k) << endl;
			

	system("pause");
	return 0;
}