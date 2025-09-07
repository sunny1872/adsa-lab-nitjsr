#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Queue implementation
typedef struct {
    int *arr;
    int front, rear, size, capacity;
} Queue;

// Create a queue
Queue* createQueue(int capacity) {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->capacity = capacity;
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->arr = (int*) malloc(capacity * sizeof(int));
    return q;
}

bool isEmptyQ(Queue* q) {
    return q->size == 0;
}

bool isFullQ(Queue* q) {
    return q->size == q->capacity;
}

void enqueue(Queue* q, int val) {
    if (isFullQ(q)) return;
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = val;
    q->size++;
}

int dequeue(Queue* q) {
    if (isEmptyQ(q)) return -1;
    int val = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return val;
}

int frontQ(Queue* q) {
    if (isEmptyQ(q)) return -1;
    return q->arr[q->front];
}

// ----------------------------
// Stack using two queues
typedef struct {
    Queue* q1;
    Queue* q2;
    int capacity;
} Stack;

// Create stack
Stack* createStack(int capacity) {
    Stack* s = (Stack*) malloc(sizeof(Stack));
    s->capacity = capacity;
    s->q1 = createQueue(capacity);
    s->q2 = createQueue(capacity);
    return s;
}

// Push element into stack
void push(Stack* s, int x) {
    // Step 1: enqueue new element into q2
    enqueue(s->q2, x);

    // Step 2: move all elements from q1 to q2
    while (!isEmptyQ(s->q1)) {
        enqueue(s->q2, dequeue(s->q1));
    }

    // Step 3: swap q1 and q2
    Queue* temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
}

// Pop element from stack
int pop(Stack* s) {
    if (isEmptyQ(s->q1)) return -1;
    return dequeue(s->q1);
}

// Peek top element
int top(Stack* s) {
    if (isEmptyQ(s->q1)) return -1;
    return frontQ(s->q1);
}

// Check if stack is empty
bool isEmpty(Stack* s) {
    return isEmptyQ(s->q1);
}

// Example usage
int main() {
    Stack* s = createStack(10);

    push(s, 10);
    push(s, 20);
    push(s, 30);

    printf("Top: %d\n", top(s));   // 30
    printf("Pop: %d\n", pop(s));   // 30
    printf("Pop: %d\n", pop(s));   // 20
    printf("Top: %d\n", top(s));   // 10
    printf("Is Empty? %d\n", isEmpty(s)); // 0 (false)

    return 0;
}
