#include <stdio.h>
#include <stdlib.h>


struct QueueItem {
    void *item;
    struct QueueItem *next;
};

struct LinkedQueue {
    struct QueueItem *head;
    struct QueueItem *tail;
};

struct LinkedQueue* newLinkedQueue();
void append(struct LinkedQueue*, void*);
void* pop(struct LinkedQueue*);
int empty(struct LinkedQueue*);

struct LinkedQueue* newLinkedQueue() {
    struct LinkedQueue *queue = malloc(sizeof(struct LinkedQueue));

    if (queue == NULL) {
        perror("Failed to allocate memory for LinkedQueue. Exiting\n");
        exit(1);
    }

    queue->head = NULL;
    queue->tail = NULL;

    return queue;
}

void append(struct LinkedQueue *queue, void *p) {
    struct QueueItem *item = malloc(sizeof(struct QueueItem));

    if (item == NULL) {
        perror("Failed to allocate memory for QueueItem. Exiting\n");
        exit(1);
    }

    item->item = p;
    item->next = NULL;

    if (queue->head == NULL)
        queue->head = item;
    else
        queue->tail->next = item;

    queue->tail = item;
}

void* pop(struct LinkedQueue *queue) {
    struct QueueItem *item;
    void *result;

    if (queue->head == NULL)
        return NULL;

    item = queue->head;

    result = item->item;
    queue->head = item->next;

    free(item);

    return result;
}

int empty(struct LinkedQueue *queue) {
    /* Returns 1 if the queue is empty, 0 otherwise */
    return (queue->head == NULL ? 1 : 0);
}
