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

//     // startΪ��ʼ�ָ��λ�ã�pathΪ�ָ�Ľ��, countΪ�Ѿ��ָ��Ĵ��������ֻ�ָܷ��Ĵ�
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
//                 break;  // һ�������㣬������ѭ������Ϊ��һ���Ǻ���ǰ��0��
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

    // startΪ��ʼ�ָ��λ�ã�pathΪ�ָ�Ľ��, countΪ�Ѿ��ָ��Ĵ��������ֻ�ָܷ��Ĵ�
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
                break;  // һ�������㣬������ѭ������Ϊ��һ���Ǻ���ǰ��0��
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