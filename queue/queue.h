#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
const int QUEUE_SIZE = 5;
const int INITIAL_VALUE_QUEUE = -1;
const int ERROR_EMPTY_QUEUE = -1;
const int ERROR_QUEUE_FULL = -2;
const int SUCCESS = 0;

struct Queue {
    int *queue;
    int end;
};

int verifyQueueIsFull (int endQueue) {
    if (endQueue == QUEUE_SIZE - 1) {
        return ERROR_QUEUE_FULL;
    } else {
        return SUCCESS;
    }
}

int verifyQueueIsEmpty (int endQueue) {
    if (endQueue == INITIAL_VALUE_QUEUE) {
        return ERROR_EMPTY_QUEUE;
    } else {
        return SUCCESS;
    }
}

int verifyEnd (struct Queue *queue) {
    return queue->end;
}

void organizeQueue (struct Queue *queue) {
    int i;
    for (i = 0; i < queue->end; i++) {
        queue->queue[i] = queue->queue[i + 1];
    }
}

int putAtTheEnd (struct Queue *queue, int value) {
    printf("Enter here");
    if (verifyQueueIsFull(queue->end) == ERROR_QUEUE_FULL) {
        return ERROR_QUEUE_FULL;
    } else {
        queue->end++;
        queue->queue[queue->end] = value;
        return SUCCESS;
    }
}

int unqueue (struct Queue *queue) {
    if (verifyQueueIsEmpty(queue->end) == ERROR_EMPTY_QUEUE) {
        return ERROR_EMPTY_QUEUE;
    } else {
        queue->end--;
        int value = queue->queue[INITIAL_VALUE_QUEUE + 1];
        if (queue->end == INITIAL_VALUE_QUEUE) {
             return value;  
        } else {
            organizeQueue(queue);
            return value;
        }
    }
}

#endif