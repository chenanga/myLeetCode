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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy_node = new ListNode();
        dummy_node->next = head;
        ListNode* fast = dummy_node;
        ListNode* slow = dummy_node;
        for (int i = 0; i < n + 1; ++i)
            fast = fast->next;

        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* del = slow->next;
        slow->next = del->next;
        delete del;
        del = nullptr;


        ListNode* ret = dummy_node->next;
        delete dummy_node;
        dummy_node = nullptr;

        return ret;
    }
};