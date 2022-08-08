#include "general.h"

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stc;
        int start = 0;
        for (int i = 0; i < pushed.size(); ++i) {
            stc.push(pushed[i]);

            while (!stc.empty() && stc.top() == popped[start]) {
                stc.pop();
                ++start;
            }
        }
        return stc.empty();
    }
};