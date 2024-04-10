#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct {
    char username[11];
    int level;
    char faction[6];
} User;

typedef struct QueueNode {
    User data;
    struct QueueNode *next;
} QueueNode;

typedef struct {
    QueueNode *head;
    QueueNode *tail;
} Queue;

Queue* createQueue();
bool isEmpty(Queue *queue);
bool enqueue(Queue *queue, User userData);
bool dequeue(Queue *queue, User *userData);
int enqueueRandomUsers(Queue *queue, int numUsers);

#endif /* QUEUE_H */
