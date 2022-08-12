#include "general.h"

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> record;

        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+") {
                int num2 = record.top();
                record.pop();
                int num1 = record.top();
                record.pop();
                record.push(num1 + num2);
            }
            else if (tokens[i] == "-") {
                int num2 = record.top();
                record.pop();
                int num1 = record.top();
                record.pop();
                record.push(num1 - num2);
            }
            else if (tokens[i] == "*") {
                int num2 = record.top();
                record.pop();
                int num1 = record.top();
                record.pop();
                record.push(num1 * num2);
            }
            else if (tokens[i] == "/") {
                int num2 = record.top();
                record.pop();
                int num1 = record.top();
                record.pop();
                record.push(num1 / num2);
            }
            else {
                record.push(stoi(tokens[i]));
            }
        }
        return record.top();
    }
};