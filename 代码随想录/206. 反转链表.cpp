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

//  // �ݹ鷨
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

// // ����
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


// �ݹ�
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
//         // ��Ե�����ж�
//         if(head == NULL) return NULL;
//         if (head->next == NULL) return head;

//         // �ݹ���ã���ת�ڶ����ڵ㿪ʼ���������
//         ListNode *last = reverseList(head->next);
//         // ��תͷ�ڵ���ڶ����ڵ��ָ��
//         head->next->next = head;
//         // ��ʱ�� head �ڵ�Ϊβ�ڵ㣬next ��Ҫָ�� NULL
//         head->next = NULL;
//         return last;
//     }
// }; 