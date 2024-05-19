#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalancedParentheses(std::string str) {
    std::stack<char> operatorStack;
    int n = str.size();

    for (int i = 0; i < n; ++i) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            operatorStack.push(str[i]);
        } else {
            if (operatorStack.empty()) {
                return false;
            }
            char top = operatorStack.top();
            operatorStack.pop();
            if ((str[i] == ')' && top != '(') || (str[i] == '}' && top != '{') || (str[i] == ']' && top != '[')) {
                return false;
            }
        }
    }
    
    return operatorStack.empty();
}

int main() {
    std::string expression;
    std::getline(std::cin, expression);
    if (isBalancedParentheses(expression)) {
        std::cout << "The expression is balanced." << endl;
    } else {
        std::cout << "The expression is not balanced." << endl;
    }
    return 0;
}