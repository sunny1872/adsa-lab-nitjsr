// C program to evaluate value of a postfix
// expression having multiple digit operands

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

// Stack structure
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// Function to initialize stack
void initStack(Stack *stack) {
    stack->top = -1;
}

// Function to push an element onto the stack
void push(Stack *stack, int value) {
    if (stack->top < MAX_SIZE - 1) {
        stack->data[++stack->top] = value;
    }
}

// Function to pop an element from the stack
int pop(Stack *stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top--];
    }
    return 0; 
}

// Function to evaluate postfix expression 
// given as an array of strings
int evaluatePostfix(char *arr[], int size) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; i < size; i++) {
        char *token = arr[i];

        // If token is a number, push it onto the stack
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(&stack, atoi(token));
        } 
        // Otherwise, it must be an operator
        else {
            int val1 = pop(&stack);
            int val2 = pop(&stack);

            if (strcmp(token, "+") == 0) {
                push(&stack, val2 + val1);
            } else if (strcmp(token, "-") == 0) {
                push(&stack, val2 - val1);
            } else if (strcmp(token, "*") == 0) {
                push(&stack, val2 * val1);
            } else if (strcmp(token, "/") == 0) {
                push(&stack, val2 / val1);
            }
        }
    }
    return pop(&stack);
}

int main() {
    char *arr[] = {"2", "3", "1", "*", "+", "9", "-"};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", evaluatePostfix(arr, size)); 
    return 0;
}
