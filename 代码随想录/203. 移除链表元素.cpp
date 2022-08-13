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
        ListNode* dummyNode = new ListNode(-1); //��ֹͷ�ڵ���Ҫɾ����ֵ������ʹ��һ������ͷ�ڵ�

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