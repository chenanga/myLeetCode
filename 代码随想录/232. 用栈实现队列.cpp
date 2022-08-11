#include "general.h"

class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        st2_.push(x);
    }

    int pop() {

        int temp = this->peek();
        st1_.pop();
        return temp;
    }

    int peek() {
        if (st1_.empty()) {
            while (!st2_.empty()) {
                st1_.push(st2_.top());
                st2_.pop();
            }
        }

        return st1_.top();
    }

    bool empty() {
        return st1_.empty() && st2_.empty();
    }
private:
    stack<int> st1_;
    stack<int> st2_;

};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */