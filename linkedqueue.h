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
