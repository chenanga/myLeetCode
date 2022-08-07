#include "general.h"

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        t.erase(t.begin());
        t.erase(t.end() - 1);

        int j = 0;
        vector<int> next(s.size(), 0);
        for (int i = 1; i < s.size(); ++i) {
            while (j > 0 && s[i] != s[j])
                j = next[j - 1];
            if (s[i] == s[j])
                ++j;
            next[i] = j;
        }
        j = 0;
        for (int i = 0; i < t.size(); ++i) {
            while (j > 0 && t[i] != s[j])
                j = next[j - 1];
            if (t[i] == s[j])
                ++j;
            if (j == s.size()) {
                return true;
            }
        }
        return false;

    }
};