#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int size;
    int front;
    int back;
    int entered;
    int *arr;
} MyCircularQueue;

// Create a new circular queue
MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*) malloc(sizeof(MyCircularQueue));
    obj->size = k;
    obj->front = 0;
    obj->back = -1;
    obj->entered = 0;
    obj->arr = (int*) malloc(k * sizeof(int));
    return obj;
}

// Insert element into circular queue
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (obj->entered == obj->size) return false;  // full
    obj->back = (obj->back + 1) % obj->size;
    obj->arr[obj->back] = value;
    obj->entered++;
    return true;
}

// Delete element from circular queue
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj->entered == 0) return false;  // empty
    obj->front = (obj->front + 1) % obj->size;
    obj->entered--;
    return true;
}

// Get front element
int myCircularQueueFront(MyCircularQueue* obj) {
    if (obj->entered == 0) return -1;
    return obj->arr[obj->front];
}

// Get rear element
int myCircularQueueRear(MyCircularQueue* obj) {
    if (obj->entered == 0) return -1;
    return obj->arr[obj->back];
}

// Check if empty
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->entered == 0;
}

// Check if full
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->entered == obj->size;
}

// Free memory
void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->arr);
    free(obj);
}

// Example usage
int main() {
    MyCircularQueue* q = myCircularQueueCreate(3);

    printf("Enqueue 10: %d\n", myCircularQueueEnQueue(q, 10));
    printf("Enqueue 20: %d\n", myCircularQueueEnQueue(q, 20));
    printf("Enqueue 30: %d\n", myCircularQueueEnQueue(q, 30));
    printf("Enqueue 40 (should fail): %d\n", myCircularQueueEnQueue(q, 40));

    printf("Rear: %d\n", myCircularQueueRear(q));
    printf("Is Full? %d\n", myCircularQueueIsFull(q));

    printf("Dequeue: %d\n", myCircularQueueDeQueue(q));
    printf("Enqueue 40: %d\n", myCircularQueueEnQueue(q, 40));
    printf("Rear: %d\n", myCircularQueueRear(q));

    myCircularQueueFree(q);
    return 0;
}
