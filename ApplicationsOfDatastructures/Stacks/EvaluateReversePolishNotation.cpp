#include <iostream>
#include <stack>
#include <vector>
#include <cstdlib>

int evalRPN(std::vector<std::string>& tokens) {
    std::stack<int> operandStack;
    for(const std::string& token : tokens) {
        if(isdigit(token[0]) || (token.size() > 0 && isdigit(token[1]))) {
            operandStack.push(stoi(token));
        }
        else {
            int op2 = operandStack.top();
            operandStack.pop();
            int op1 = operandStack.top();
            operandStack.pop();

            switch(token[0]) {
                case '+' : operandStack.push(op1 + op2);
                            break;
                case '-' : operandStack.push(op1 - op2);
                            break;
                case '*' : operandStack.push(op1 * op2);
                            break;
                case '/' : operandStack.push(op1 / op2); 
            }
        }
    }

    return operandStack.top();
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> input(n);
    
    for(int i=0; i<n; ++i) {
        std::cin >> input[i];
    }

    std::cout << "Result: " << evalRPN(input) << '\n';
    return 0;
}