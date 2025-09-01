#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

char peek(struct Stack* stack) {
    return stack->array[stack->top];
}

void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

char pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^');
}

int getPrecedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/' || op == '%')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(char* infix) {
    struct Stack* stack = createStack(strlen(infix));
    int i, j;

    for (i = 0, j = -1; infix[i]; ++i) {
        if (isalnum(infix[i]))
            infix[++j] = infix[i];
        else if (infix[i] == '(')
            push(stack, infix[i]);
        else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(')
                infix[++j] = pop(stack);
            if (!isEmpty(stack) && peek(stack) == '(')
                pop(stack);
        } else if (isOperator(infix[i])) {
            while (!isEmpty(stack) && getPrecedence(infix[i]) <= getPrecedence(peek(stack)))
                infix[++j] = pop(stack);
            push(stack, infix[i]);
        }
    }

    while (!isEmpty(stack))
        infix[++j] = pop(stack);

    infix[++j] = '\0';

    printf("%s\n", infix);
}

int main() {
    int n;
    scanf("%d", &n);
    char infix[n];
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}
