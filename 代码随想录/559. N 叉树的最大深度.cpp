#include "general.h"
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        return __maxDepth(root);
    }
private:
    int __maxDepth(Node* root) {
        if (root == nullptr) return 0;
        int max_depth = 0;
        auto& v = root->children;
        for (int i = 0; i < v.size(); ++i) {
            max_depth = max(max_depth, __maxDepth(v[i]));
        }
        return max_depth + 1;
    }
};