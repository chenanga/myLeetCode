#include "general.h"

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        __findMode(root);
        return res;
    }

private:
    TreeNode* pre = nullptr;
    int count = 1, max_count = 1;
    vector<int> res;
    void __findMode(TreeNode* cur) {
        if (cur == nullptr) return;
        __findMode(cur->left);
        if (pre == nullptr) {
            count = 1;
        } else if (cur->val == pre->val) {
            count++;
        } else {
            count = 1;
        }

        if (count > max_count) {
            max_count = count;
            res.clear();
        }
        if (count == max_count) {
            res.push_back(cur->val);
        }

        pre = cur;
        __findMode(cur->right);
    }
};