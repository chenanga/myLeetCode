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

  // �ݹ鷨
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        return reverse(nullptr, head);
    }
private:
    ListNode* reverse(ListNode* pre, ListNode* cur) {
        if (cur == nullptr)
            return pre;

        ListNode* next = cur->next;
        cur->next = pre;

        return reverse(cur, next);
    }
};