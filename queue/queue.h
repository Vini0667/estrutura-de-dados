#ifndef QUEUE_H
#define QUEUE_H

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

void organizeQueue (struct Queue *queue) {
    // if () {
    // 
    //
    //     int aux, i;
    //
    //     for (i = QUEUE_SIZE; i < QUEUE_SIZE; i++) {
    //         queue->queue[i];
    //     }
    // }
}

int putAtTheEnd (struct Queue *queue, int value) {
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
        organizeQueue(queue);
        return value;
    }
}

#endif