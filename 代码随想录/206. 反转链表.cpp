/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include "listNode.h"

 /**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     ListNode *next;
  *     ListNode() : val(0), next(nullptr) {}
  *     ListNode(int x) : val(x), next(nullptr) {}
  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
  * };
  */
  // class Solution {
  // public:
  //     ListNode* reverseList(ListNode* head) {

  //         ListNode* pre = nullptr;
  //         ListNode* cur = head;
  //         while (cur != nullptr) {
  //             ListNode* next = cur->next;
  //             cur->next = pre;
  //             pre = cur;
  //             cur = next;
  //         }

  //         return pre;
  //     }
  // };

//  // 递归法
//class Solution {
//public:
//    ListNode* reverseList(ListNode* head) {
//
//        return reverse(nullptr, head);
//    }
//private:
//    ListNode* reverse(ListNode* pre, ListNode* cur) {
//        if (cur == nullptr)
//            return pre;
//
//        ListNode* next = cur->next;
//        cur->next = pre;
//
//        return reverse(cur, next);
//    }
//};

// // 迭代
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {

//         ListNode* pre = nullptr;
//         ListNode* cur = head;
//         while (cur) {
//             ListNode* next = cur->next;
//             cur->next = pre;
//             pre = cur;
//             cur = next;
//         }
//         return pre;
//     }

// };


// 递归
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return __reverseList(nullptr, head);
    }
private:
    ListNode* dummyNode;
    ListNode* __reverseList(ListNode* pre, ListNode* cur) {
        if (cur == nullptr)
            return pre;
        ListNode* next = cur->next;
        cur->next = pre;
        return __reverseList(cur, next);
    }

};

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         // 边缘条件判断
//         if(head == NULL) return NULL;
//         if (head->next == NULL) return head;

//         // 递归调用，翻转第二个节点开始往后的链表
//         ListNode *last = reverseList(head->next);
//         // 翻转头节点与第二个节点的指向
//         head->next->next = head;
//         // 此时的 head 节点为尾节点，next 需要指向 NULL
//         head->next = NULL;
//         return last;
//     }
// }; 