#include "general.h"

// class Solution {
// public:
//     bool isValid(string s) {
//         if(s.size()%2 == 1 ) return false; // 奇数个无法匹配
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

// todo 优化，在左括号入栈时候，push对应的右括号，后续只需要判断栈顶是否和右括号相同
class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1) return false; // 奇数个无法匹配
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