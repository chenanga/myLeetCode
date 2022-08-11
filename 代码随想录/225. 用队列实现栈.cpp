#include "general.h"

class MyStack {
public:
    MyStack() {

    }

    void push(int x) {
        que_.push(x);
    }

    int pop() {
        int size = que_.size();
        for (int i = 0; i < size - 1; ++i) {
            que_.push(que_.front());
            que_.pop();
        }
        int temp = que_.front();
        que_.pop();
        return temp;
    }

    int top() {
        return que_.back();
    }

    bool empty() {
        return que_.empty();
    }
private:
    queue<int> que_;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */