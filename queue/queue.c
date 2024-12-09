#include <stdio.h>
#include <stdlib.h>

const int QUEUE_SIZE = 5;
const int INITIAL_VALUE_QUEUE = -1;
const int ERROR_EMPTY_QUEUE = -1;
const int ERROR_QUEUE_FULL = -2;
const int SUCCESS_OPERATION = 0;

struct Queue {
    int *queue;
    int end;
};

int verifyQueueIsFull (int endQueue) {
    if (endQueue == QUEUE_SIZE - 1) {
        return SUCCESS_OPERATION;
    } else {
        return ERROR_QUEUE_FULL;
    }
}

int verifyQueueIsEmpty (int endQueue) {
    if (endQueue == INITIAL_VALUE_QUEUE) {
        return SUCCESS_OPERATION;
    } else {
        
    }
}

void organizeQueue (struct Queue *queue) {

}

int putAtTheEnd (struct Queue *queue, int value) {
    if (verifyQueueIsFull(queue->end) == SUCCESS_OPERATION) {
        return ERROR_QUEUE_FULL;
    } else {
        queue->end++;
        queue->queue[queue->end] = value;
        return SUCCESS_OPERATION;
    }
}


int unqueue (struct Queue *queue) {

}

int main (void) {
    struct Queue queue = {
        (int*)malloc(QUEUE_SIZE * sizeof(int)),
        INITIAL_VALUE_QUEUE
    };

    int i;

    for (i = 0; i < QUEUE_SIZE; i++) {
        printf("\n\n%i\n\n", queue.queue[i]);
    }
    

    return 0;
}