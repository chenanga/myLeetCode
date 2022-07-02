#include <iostream>
#include <vector>
#include <string>

using namespace std;

// class Solution {
// public:
//     int monotoneIncreasingDigits(int n) {

//         string str = to_string(n);
//         int index = str.size();
//         for (int i = str.size() - 1; i > 0; -- i) {
//             if (str[i] < str[i - 1]) {
//                 str[i - 1] --;
//                 index = i;
//             }
//         }

//         // ��λ���Ժ󶼸�ֵΪ9
//         for (int i = index; i < str.size(); ++ i)
//             str[i] = '9';

//         return stoi(str);
//     }
// };

/*
ʹ��һ��������¼�Ѿ��������ֵ�������֣�
*/
class Solution {
public:
    int monotoneIncreasingDigits(int n) {

        string str = to_string(n);
        int maxIdx = 0;
        // ���������ҵ���һ���ݼ���
        for (int i = 0; i < str.size() - 1; ++i) {
            if (str[i] > str[maxIdx]) {
                maxIdx = i;
            }

            if (str[i] > str[i + 1]) {
                str[maxIdx] --;
                // ��λ���Ժ󶼸�ֵΪ9
                for (int j = maxIdx + 1; j < str.size(); ++j)
                    str[j] = '9';
                break;
            }
        }

        return stoi(str);
    }
};

int main() {

	system("pause");
	return 0;
}