#include "general.h"
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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy_node = new ListNode();
        dummy_node->next = head;
        ListNode* pre = dummy_node;
        ListNode* cur = head;

        while (cur != nullptr && cur->next != nullptr) {
            ListNode* next = cur->next;
            pre->next = next;
            cur->next = next->next;
            next->next = cur;
            pre = cur;
            cur = cur->next;
        }
        ListNode* ret = dummy_node->next;
        delete dummy_node;
        dummy_node = nullptr;
        return ret;
    }
};