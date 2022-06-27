#include <iostream>
#include <vector>
#include <string>

using namespace std;

// class Solution {
// public:
//     vector<string> restoreIpAddresses(string s) {
//         __restoreIpAddresses(s, 0, "", 0);
//         return result;
//     }

// private:
//     vector<string>result;

//     // start为开始分割的位置，path为分割的结果, count为已经分隔的次数，最多只能分割四次
//     void __restoreIpAddresses(const string & s, int start, string path, int count) {
//         if (count >= 4 && start < s.size()) 
//             return;
//         if (start >= s.size() && count == 4) {
//             path.pop_back();
//             result.push_back(path);
//             return;
//         }

//         for (int i = start; i < s.size(); ++ i) {
//             if (i == start && s[start] == '0') {
//                 __restoreIpAddresses(s, i + 1, path + s[i] + '.', count + 1);
//                 break;  // 一旦不满足，则跳出循环，因为下一次是含有前导0的
//             }
//             else {
//                 string str = s.substr(start, i - start + 1);
//                 int num = stoi(str);
//                 if (num <= 255)
//                     __restoreIpAddresses(s, i + 1, path + str + '.', count + 1);
//                 else
//                     break;
//             }

//         }
//         return;


//     }
// };


class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        __restoreIpAddresses(s, 0, "", 0);
        return result;
    }

private:
    vector<string>result;

    // start为开始分割的位置，path为分割的结果, count为已经分隔的次数，最多只能分割四次
    void __restoreIpAddresses(const string& s, int start, const string& path, int count) {
        if (count >= 4 && start < s.size())
            return;
        if (start >= s.size() && count == 4) {
            result.push_back(path);
            return;
        }

        for (int i = start; i < s.size(); ++i) {
            if (i == start && s[start] == '0') {
                if (count == 3)
                    __restoreIpAddresses(s, i + 1, path + s[i], count + 1);
                else
                    __restoreIpAddresses(s, i + 1, path + s[i] + '.', count + 1);
                break;  // 一旦不满足，则跳出循环，因为下一次是含有前导0的
            }
            else {
                string str = s.substr(start, i - start + 1);
                int num = stoi(str);
                if (num <= 255) {
                    if (count == 3)
                        __restoreIpAddresses(s, i + 1, path + str, count + 1);

                    else
                        __restoreIpAddresses(s, i + 1, path + str + '.', count + 1);


                }
                else
                    break;
            }

        }
        return;


    }
};

int main() {

	system("pause");
	return 0;
}