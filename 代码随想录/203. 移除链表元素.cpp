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

#include "general.h"


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyNode = new ListNode(-1); //防止头节点是要删除的值，所有使用一个虚拟头节点

        dummyNode->next = head;
        ListNode* pre = dummyNode;
        ListNode* cur = head;

        while (cur != nullptr) {
            if (cur->val == val) {
                pre->next = cur->next;
                delete cur;
                cur = pre->next;
            }
            else {
                pre = cur;
                cur = cur->next;
            }
        }
        ListNode* ret = dummyNode->next;
        delete dummyNode;
        return ret;
    }
};