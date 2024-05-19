#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 50

struct Stack {
    int top;
    int arr[MAX_SIZE];
};

void push(struct Stack *stack, int item) {
    if(stack->top == MAX_SIZE-1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = item;
}

int pop(struct Stack *stack) {
    if(stack->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

int evaluateRPN(char **tokens, int tokensSize) {
    struct Stack operandStack;
    operandStack.top = -1;
    for(int i=0; i<tokensSize; ++i) {
        if(isdigit(tokens[i][0]) || (strlen(tokens[i]) > 1 && isdigit(tokens[i][1]))) {
            push(&operandStack, atoi(tokens[i]));
        }
        else {
            int op2 = pop(&operandStack);
            int op1 = pop(&operandStack);

            switch(tokens[i][0]) {
                case '+' :
                    push(&operandStack, op1+op2);
                    break;
                case '-' :
                    push(&operandStack, op1-op2);
                    break;
                case '*' :
                    push(&operandStack, op1*op2);
                    break;
                case '/' :
                    push(&operandStack, op1/op2);
                    break;
            }
        }
    }

    return pop(&operandStack);
}

int main() {

    int n;
    scanf("%d", &n);
    char **tokens = (char **)malloc(n * sizeof(char *));
    for(int i=0; i<n; ++i) {
       tokens[i] = (char *)malloc(n * sizeof(char));
       scanf("%s", tokens[i]);
    }
    printf("%d\n", evaluateRPN(tokens, n));
    
    for (int i = 0; i < n; ++i) {
        free(tokens[i]);
    }
    free(tokens);

    return 0;
}