#include "general.h"
// //ֱ������
// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         vector<int> ans;
//         for (int num: nums) {
//             ans.push_back(num * num);
//         }
//         sort(ans.begin(), ans.end());
//         return ans;
//     }
// };



// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         vector<int> res;
//         //û�и���
//         if (nums[0] >= 0) {
//             for (int i = 0; i < nums.size(); ++ i) {
//                 res.push_back(nums[i] * nums[i]);
//             }
//             return res;
//         }
//         //û������
//         if (nums[nums.size() - 1] <= 0) {
//             for (int i = nums.size() - 1; i >= 0; -- i) {
//                 res.push_back(nums[i] * nums[i]);
//             }
//             return res;
//         }
//         //���߶���
//         //�ȶ��ֲ��ҵ������ֽ��
//         int left = 0, right = nums.size();
//         while (left <= right) {
//             int mid = left + (right - left) / 2;
//             if (nums[mid] <= 0 && nums[mid + 1] > 0) {
//                 left = mid;
//                 right = mid + 1;
//                 break;
//             }
//             else if (nums[mid] > 0)
//                 right = mid - 1;
//             else   //nums[mid] < 0
//                 left = mid + 1;

//         }
//         int leftSqrt, rightSqrt;
//         while (left >= 0 && right < nums.size()) {

//             leftSqrt = nums[left] * nums[left];
//             rightSqrt = nums[right] * nums[right];

//             if (leftSqrt >= rightSqrt) {
//                 res.push_back(rightSqrt);
//                 ++ right;
//             }
//             else { //leftSqrt < rightSqrt
//                 res.push_back(leftSqrt);
//                 -- left;
//             }
//         }
//         if (left < 0 && right > nums.size()) //�պý���
//             return res;
//         else if (left >= 0) {                //��߻�������û����
//             for (int i = left; i >= 0; -- i) {
//                 res.push_back(nums[i] * nums[i]);
//             }
//             return res;
//         }
//         else { //right < num.size()          //�ұ߻�������û����
//             for (int i = right; i < nums.size(); ++ i) {
//                 res.push_back(nums[i] * nums[i]);
//             }
//             return res;
//         }

//     }
// };

// //�Ż�,ʱ�����һЩ
// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         vector<int> res;
//         //û�и���
//         if (nums[0] >= 0) {
//             for (int i = 0; i < nums.size(); ++ i) {
//                 res.push_back(nums[i] * nums[i]);
//             }
//             return res;
//         }
//         //û������
//         if (nums[nums.size() - 1] <= 0) {
//             for (int i = nums.size() - 1; i >= 0; -- i) {
//                 res.push_back(nums[i] * nums[i]);
//             }
//             return res;
//         }
//         //���߶���
//         //�ȶ��ֲ��ҵ������ֽ��
//         int left = 0, right = nums.size();
//         while (left <= right) {
//             int mid = left + (right - left) / 2;
//             if (nums[mid] <= 0 && nums[mid + 1] > 0) {
//                 left = mid;
//                 right = mid + 1;
//                 break;
//             }
//             else if (nums[mid] > 0)
//                 right = mid - 1;
//             else   //nums[mid] < 0
//                 left = mid + 1;

//         }
//         int leftSqrt = nums[left] * nums[left], rightSqrt = nums[right] * nums[right];
//         // cout << " !" << endl;
//         while (left >= 0 && right < nums.size()) {

//             if (leftSqrt >= rightSqrt) {
//                 res.push_back(rightSqrt);
//                 ++ right;
//                 if (right < nums.size())
//                     rightSqrt = nums[right] * nums[right];
//             }
//             else { //leftSqrt < rightSqrt
//                 res.push_back(leftSqrt);
//                 -- left;
//                 if (left >= 0)
//                     leftSqrt = nums[left] * nums[left];
//             }
//         }

//         if (left < 0 && right > nums.size()) //�պý���
//             return res;
//         else if (left >= 0) {                //��߻�������û����
//             for (int i = left; i >= 0; -- i) {
//                 res.push_back(nums[i] * nums[i]);
//             }
//             return res;
//         }
//         else { //right < num.size()          //�ұ߻�������û����
//             for (int i = right; i < nums.size(); ++ i) {
//                 res.push_back(nums[i] * nums[i]);
//             }
//             return res;
//         }

//     }
// };

// //�ٷ����ָ����������汾
// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         int n = nums.size();
//         int negative = -1;
//         for (int i = 0; i < n; ++i) {
//             if (nums[i] < 0) {
//                 negative = i;
//             } else {
//                 break;
//             }
//         }

//         vector<int> ans;
//         int i = negative, j = negative + 1;
//         while (i >= 0 || j < n) {
//             if (i < 0) {
//                 ans.push_back(nums[j] * nums[j]);
//                 ++j;
//             }
//             else if (j == n) {
//                 ans.push_back(nums[i] * nums[i]);
//                 --i;
//             }
//             else if (nums[i] * nums[i] < nums[j] * nums[j]) {
//                 ans.push_back(nums[i] * nums[i]);
//                 --i;
//             }
//             else {
//                 ans.push_back(nums[j] * nums[j]);
//                 ++j;
//             }
//         }

//         return ans;
//     }
// };


// //�ٷ�˫ָ��,���迼�Ǳ߽��
// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans(n);
//         for (int i = 0, j = n - 1, pos = n - 1; i <= j;) {
//             if (nums[i] * nums[i] > nums[j] * nums[j]) {
//                 ans[pos] = nums[i] * nums[i];
//                 ++i;
//             }
//             else {
//                 ans[pos] = nums[j] * nums[j];
//                 --j;
//             }
//             --pos;
//         }
//         return ans;
//     }
// };



//ֱ������
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int left = 0, right = nums.size() - 1, index = nums.size() - 1;
        while (left <= right) {
            int num1 = nums[left] * nums[left];
            int num2 = nums[right] * nums[right];
            if (num1 < num2) {
                ans[index--] = num2;
                --right;
            }
            else {
                ans[index--] = num1;
                ++left;
            }
        }

        return ans;
    }
};