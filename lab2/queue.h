#ifndef QUEUE_H
#define QUEUE_H
#include "list.h"

typedef struct Queue {
    List *list;
} Queue;

Queue *queue_new(Queue *queue);
void queue_push_front(Queue *queue, char *id, int ta, int ts);
void queue_push_back(Queue *queue, char *id, int ta, int ts);
int queue_remove(Queue *queue, char *id);
void queue_print_time(Queue *queue, int time);
Data *queue_find(Queue *queue, int time);

#endif //QUEUE_H.
