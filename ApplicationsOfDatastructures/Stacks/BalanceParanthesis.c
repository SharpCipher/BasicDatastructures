#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 10

struct Stack {
    int top;
    int arr[MAX_SIZE];
};

void push(struct Stack *stack, int item) {
    if(stack->top == MAX_SIZE-1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack->arr[++stack->top] = item;
}

int pop(struct Stack *stack) {
    if(stack->top == -1) {
        printf("Stack Underflow!\n");
        return '\0';
    }
    return stack->arr[stack->top--];
}

bool isMatchingPair(char p1, char p2) {
    if(p1 == '(' && p2 == ')') {
        return true;
    }
    else if(p1 == '{' && p2 == '}') {
        return true;
    }
    else if(p1 == '[' && p2 == ']') {
        return true;
    }
    else {
        return false;
    }
}

bool isBalanced(char *expression) {
    struct Stack stack;
    stack.top = -1;

    for(int i=0; i<strlen(expression); ++i) {
        if(expression[i] == '(' || expression[i] == '{' || expression[i] == '[') {
            push(&stack, expression[i]);
        }
        else if(expression[i] == ')' || expression[i] == '}' || expression[i] == ']') {
            if(stack.top == -1 || !isMatchingPair(pop(&stack), expression[i])) {
                return false;
            }
        }
    }
    return stack.top == -1;
}

int main() {
    char* expression;
    expression = (char*)malloc(MAX_SIZE * sizeof(char));
    scanf("%s", expression);

    printf("%d\n", isBalanced(expression));
    return 0;
}