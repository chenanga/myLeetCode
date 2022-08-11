#include "general.h"

// class Solution {
// public:
//     bool isValid(string s) {
//         if(s.size()%2 == 1 ) return false; // �������޷�ƥ��
//         stack<char> stc;

//         for (int i = 0; i < s.size(); ++i) {
//             if (s[i] == '(' || s[i] == '{' || s[i] == '[')
//                 stc.push(s[i]);
//             else {
//                 if (stc.empty())
//                     return false;
//                 char ch = stc.top();
//                 if (ch == '(' && s[i] == ')')
//                     stc.pop();
//                 else if (ch == '{' && s[i] == '}')
//                     stc.pop();
//                 else if (ch == '[' && s[i] == ']')
//                     stc.pop();
//                 else
//                     return false;
//             }
//         }
//         return stc.empty();
//     }
// };

// todo �Ż�������������ջʱ��push��Ӧ�������ţ�����ֻ��Ҫ�ж�ջ���Ƿ����������ͬ
class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1) return false; // �������޷�ƥ��
        stack<char> stc;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                stc.push(s[i]);
            else {
                if (stc.empty())
                    return false;
                char ch = stc.top();
                if (ch == '(' && s[i] == ')')
                    stc.pop();
                else if (ch == '{' && s[i] == '}')
                    stc.pop();
                else if (ch == '[' && s[i] == ']')
                    stc.pop();
                else
                    return false;
            }
        }
        return stc.empty();
    }
};