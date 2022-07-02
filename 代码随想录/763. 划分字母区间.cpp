#include <iostream>
#include <vector>

using namespace std;

// // 
// class Solution {
// public:
//     vector<int> partitionLabels(string s) {
//         // ����ѭ����ÿ��¼һ����ĸ�����жϸ�λ�ú����Ƿ����ظ����ֵģ�����У�������ѭ����������¼��ĸ��ֱ������ �������ظ����ֵģ���ʱΪһ���⣬����result������index
//         int record[26] = {0};
//         vector<int> result;
//         int index = 0;
//         for (int i = 0; i < s.size(); ++ i) {
//             record[s[i] - 'a'] ++;
//             int j = i + 1;
//             for ( ; j < s.size(); ++ j) {
//                 if (record[s[j] - 'a'] != 0)
//                     break;
//             }
//             if (j == s.size()) {
//                 // ˵������û�г��ֵ�ǰ����ĸ�ˣ�
//                 result.push_back(i - index + 1);
//                 index = i + 1;
//             }
//         }
//         return result;
//     }
// };

// 
class Solution {
public:
    vector<int> partitionLabels(string s) {
        // ����ѭ����ÿ��¼һ����ĸ�����жϸ�λ�ú����Ƿ����ظ����ֵģ�����У�������ѭ����������¼��ĸ��ֱ������ �������ظ����ֵģ���ʱΪһ���⣬����result������index
        int record[26] = { 0 };  // ��¼���ַ�����Զ�߽�
        vector<int> result;
        for (int i = 0; i < s.size(); ++i)
            record[s[i] - 'a'] = i;

        int left = 0, right = 0;  // ��ǰ�ַ�������Զ����
        for (int i = 0; i < s.size(); ++i) {
            right = max(right, record[s[i] - 'a']);

            if (i == right) {
                // ˵������û�г��ֵ�ǰ����ĸ�ˣ�
                result.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return result;
    }
};

int main() {

	system("pause");
	return 0;
}