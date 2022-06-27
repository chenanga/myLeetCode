// class MyLinkedList {

// struct ListNode {
//     int val;
//     ListNode* next;
//     ListNode* pre;
//     ListNode(int x) : val(x), next(nullptr), pre(nullptr) {}
// };
// public:
//     MyLinkedList() {
//         dummyNode = new ListNode(-1);
//         endNode = new ListNode(-1);
//         dummyNode->next = endNode;
//         endNode->pre =  dummyNode;
//     }

//     int get(int index) {
//         if (index < record.size()) {
//             return record[index]->val;
//         }
//         return -1;
//     }

//     void addAtHead(int val) {
//         ListNode* temp = dummyNode->next;
//         dummyNode->next = new ListNode(val);
//         dummyNode->next->pre = dummyNode;
//         dummyNode->next->next = temp;
//         temp->pre = dummyNode->next;
//         record.insert(record.begin(), dummyNode->next); // 维护数组
//     }

//     void addAtTail(int val) {
//         ListNode* temp = endNode->pre;
//         temp->next = new ListNode(val);
//         temp->next->pre = temp;
//         temp->next->next = endNode;
//         endNode->pre = temp->next;
//         record.push_back(temp->next);   // 维护数组
//     }

//     void addAtIndex(int index, int val) {
//         if (index <= 0) 
//             addAtHead(val);
//         else if (index == record.size())
//             addAtTail(val);
//         else if (index < record.size()) {
//             ListNode* temp = new ListNode(val);
//             ListNode* cur = record[index];
//             ListNode* pre = cur->pre;
//             pre->next = temp;
//             temp->next = cur;
//             temp->pre = pre;
//             cur->pre = temp;
//             record.insert(record.begin() + index, temp);
//         }
//     }

//     void deleteAtIndex(int index) {
//         if (index >= 0 && index < record.size()) {
//             ListNode* del = record[index];
//             ListNode* pre = del->pre;
//             ListNode* next = del->next;
//             pre->next = next;
//             next->pre = pre;
//             delete del;
//             record.erase(record.begin() + index);
//         }

//     }
// private:
//     vector<ListNode*> record;
//     ListNode * dummyNode, * endNode;
// };

// 不使用vector的版本  todo
class MyLinkedList {

private:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode* pre;
        ListNode(int x) : val(x), next(nullptr), pre(nullptr) {}
    };
public:
    MyLinkedList() {
        dummyNode = new ListNode(-1);
        endNode = new ListNode(-1);
        dummyNode->next = endNode;
        endNode->pre = dummyNode;
        len = 0;
    }

    int get(int index) {
        if (index < len) {
            //遍历到index个
            ListNode* cur = dummyNode->next;
            for (int i = 0; i < index; ++i)
                cur = cur->next;
            return cur->val;
        }
        return -1;
    }

    void addAtHead(int val) {
        ListNode* temp = dummyNode->next;
        dummyNode->next = new ListNode(val);
        dummyNode->next->pre = dummyNode;
        dummyNode->next->next = temp;
        temp->pre = dummyNode->next;
        ++len;
    }

    void addAtTail(int val) {
        ListNode* temp = endNode->pre;
        temp->next = new ListNode(val);
        temp->next->pre = temp;
        temp->next->next = endNode;
        endNode->pre = temp->next;
        ++len;
    }

    void addAtIndex(int index, int val) {
        if (index <= 0)
            addAtHead(val);
        else if (index == len)
            addAtTail(val);
        else if (index < len) {
            ListNode* temp = new ListNode(val);

            ListNode* cur = dummyNode->next;
            for (int i = 0; i < index; ++i)
                cur = cur->next;
            ListNode* pre = cur->pre;

            pre->next = temp;
            temp->next = cur;
            temp->pre = pre;
            cur->pre = temp;
            ++len;
        }
    }

    void deleteAtIndex(int index) {
        if (index >= 0 && index < len) {
            ListNode* del = dummyNode->next;
            for (int i = 0; i < index; ++i)
                del = del->next;
            ListNode* pre = del->pre;
            ListNode* next = del->next;
            pre->next = next;
            next->pre = pre;
            delete del;
            --len;
        }

    }
private:
    ListNode* dummyNode, * endNode;
    int len;
};
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */