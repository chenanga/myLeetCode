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
// /*
// // Definition for a Node.
// class Node {
// public:
//     int val;
//     vector<Node*> children;

//     Node() {}

//     Node(int _val) {
//         val = _val;
//     }

//     Node(int _val, vector<Node*> _children) {
//         val = _val;
//         children = _children;
//     }
// };
// */

// class Solution {
// public:
//     vector<vector<int>> levelOrder(Node* root) {
//         if (root == nullptr) return {};
//         vector<vector<int>> res;
//         queue<Node*> que;
//         que.push(root);
//         res.push_back({root->val});
//         while (!que.empty()) {
//             int size = que.size();
//             vector<int> v;
//             for (int i = 0; i < size; ++ i) {
//                 Node* node = que.front();
//                 que.pop();
//                 for (int j = 0; j < (node->children).size(); ++ j) {
//                     v.push_back((node->children)[j]->val);
//                     que.push((node->children)[j]);
//                 }
//             }
//             if (!v.empty())
//                 res.push_back(v);
//         }

//         return res;
//     }
// };



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
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) return {};
        vector<vector<int>> res;
        queue<Node*> que;
        que.push(root);

        while (!que.empty()) {
            int size = que.size();
            vector<int> v;
            for (int i = 0; i < size; ++i) {
                Node* node = que.front();
                que.pop();
                v.push_back(node->val);
                for (int j = 0; j < (node->children).size(); ++j) {
                    que.push((node->children)[j]);
                }
            }

            res.push_back(v);
        }

        return res;
    }
};