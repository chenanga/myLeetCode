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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        ListNode* node_a = headA;
        ListNode* node_b = headB;

        while (node_a || node_b) {

            if (node_a == nullptr) {
                node_a = headB;
            }
            if (node_b == nullptr) {
                node_b = headA;
            }
            if (node_a == node_b) {
                return node_a;
            }
            node_b = node_b->next;
            node_a = node_a->next;
        }
        return nullptr;

    }
};