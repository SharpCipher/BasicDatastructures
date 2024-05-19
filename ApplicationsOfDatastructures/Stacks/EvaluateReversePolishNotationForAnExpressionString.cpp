#include <iostream>
#include <stack>
#include <vector>

int evalRPN(std::string& input, int n) {
    std::stack<int> operandStack;
    for(int i=0; i<n; ++i) {
        if(isdigit(input[i])) {
            operandStack.push(input[i] - '0');
        }
        else {
            int op2 = operandStack.top();
            operandStack.pop();
            int op1 = operandStack.top();
            operandStack.pop();

            switch(input[i]) {
                case '+' : operandStack.push(op1 + op2);
                    break;
                case '-' : operandStack.push(op1 - op2);
                    break;
                case '*' : operandStack.push(op1 * op2);
                    break;
                case '/' : operandStack.push(op1 / op2);
                    break;
            }
        }
    }
    return operandStack.top();
}

int main() {
    int n;
    std::string expression;
    std::cout << "Enter the expression string: ";
    std::getline(std::cin, expression);
    n = expression.size();

    std::cout << "Result: " << evalRPN(expression, n) << '\n';
    return 0;
}