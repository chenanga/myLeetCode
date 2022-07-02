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

//         // 该位置以后都赋值为9
//         for (int i = index; i < str.size(); ++ i)
//             str[i] = '9';

//         return stoi(str);
//     }
// };

/*
使用一个索引记录已经遍历部分的最大数字，
*/
class Solution {
public:
    int monotoneIncreasingDigits(int n) {

        string str = to_string(n);
        int maxIdx = 0;
        // 从左往右找到第一个递减的
        for (int i = 0; i < str.size() - 1; ++i) {
            if (str[i] > str[maxIdx]) {
                maxIdx = i;
            }

            if (str[i] > str[i + 1]) {
                str[maxIdx] --;
                // 该位置以后都赋值为9
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