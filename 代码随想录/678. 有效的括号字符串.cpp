#include "general.h"

class Solution {
public:
    bool checkValidString(string s) {
        int len = s.size();
        stack<int> record;  // ÐÇºÅ
        stack<int> left;  // ×óÀ¨ºÅ

        for (int i = 0; i < len; ++i) {
            if (s[i] == '(')
                left.push(i);
            else if (s[i] == '*')
                record.push(i);
            else {
                if (left.empty() && record.empty())
                    return false;
                else {
                    if (left.empty())
                        record.pop();
                    else
                        left.pop();
                }
            }
        }

        // Í³¼ÆÊ£ÓàµÄ
        while (!left.empty()) {
            int l = left.top();
            if (record.empty())
                return false;
            int r = record.top();
            if (l < r) {
                left.pop();
                record.pop();
            }
            else {
                return false;
            }

        }


        return true;

    }
};