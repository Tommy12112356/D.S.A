#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

Queue* createQueue() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        return NULL; // Memory allocation failed
    }
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

bool isEmpty(Queue *queue) {
    return queue->head == NULL;
}

bool enqueue(Queue *queue, User userData) {
    QueueNode *newNode = (QueueNode*)malloc(sizeof(QueueNode));
    if (newNode == NULL) {
        return false; // Memory allocation failed
    }
    newNode->data = userData;
    newNode->next = NULL;
    if (isEmpty(queue)) {
        queue->head = newNode;
    } else {
        queue->tail->next = newNode;
    }
    queue->tail = newNode;
    return true;
}

bool dequeue(Queue *queue, User *userData) {
    if (isEmpty(queue)) {
        return false; // Queue is empty
    }
    QueueNode *temp = queue->head;
    *userData = temp->data;
    queue->head = temp->next;
    free(temp);
    if (queue->head == NULL) {
        queue->tail = NULL; // Queue becomes empty
    }
    return true;
}

int enqueueRandomUsers(Queue *queue, int numUsers) {
    if (numUsers <= 0) {
        return -1; // Invalid number of users
    }
    char *factions[3] = {"red", "blue", "green"};
    srand(time(NULL)); // Seed for random number generation
    for (int i = 0; i < numUsers; i++) {
        User newUser;
        for (int j = 0; j < 10; j++) {
            newUser.username[j] = 'A' + rand() % 26; // Random uppercase letter
        }
        newUser.username[10] = '\0'; // Null terminator
        newUser.level = rand() % 60 + 1; // Random level between 1 and 60
        strcpy(newUser.faction, factions[rand() % 3]); // Random faction
        if (!enqueue(queue, newUser)) {
            return i; // Return the number of successfully enqueued users
        }
    }
    return 0; // Success
}
