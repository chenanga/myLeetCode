#include "general.h"
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// class Solution {
// public:
//     Node* connect(Node* root) {
//         if (root == nullptr) return nullptr;
//         queue<Node*> que;
//         que.push(root);

//         while (!que.empty()) {
//             int size = que.size();
//             Node* pre = que.front();
//             que.pop();
//             if (pre->left) que.push(pre->left);
//             if (pre->right) que.push(pre->right);
//             for (int i = 1; i < size; ++ i) {
//                 Node* cur = que.front();
//                 que.pop();
//                 pre->next = cur;
//                 if (cur->left) que.push(cur->left);
//                 if (cur->right) que.push(cur->right);

//                 pre = cur;
//             }
//         }

//         return root;        
//     }
// };


// 不使用额外空间的版本  todo
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;


        Node* cur = root;
        while (cur != nullptr) {
            Node* dummyNode = new Node();
            Node* pre = dummyNode;
            while (cur != nullptr) {
                if (cur->left) {
                    pre->next = cur->left;
                    pre = pre->next;
                }
                if (cur->right) {
                    pre->next = cur->right;
                    pre = pre->next;
                }
                cur = cur->next;
            }
            cur = dummyNode->next;
        }
        return root;
    }
};