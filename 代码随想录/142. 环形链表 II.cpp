#include "general.h"
#include "listNode.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (head == nullptr)
            return nullptr;

        ListNode* slow = head;
        ListNode* fast = slow;

        while (slow && fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;

            if (slow == fast) {
                ListNode* start = head;
                while (start != fast) {
                    start = start->next;
                    fast = fast->next;
                }
                return start;
            }

        }
        return nullptr;
    }
};