#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "list.h"

Queue *queue_new(Queue *queue) {
        List *list = (List *) calloc(1, sizeof(List));
        queue->list = list_init(list);
        return queue;
}

void queue_push_front(Queue *queue, char *id, int ta, int ts) {
        list_push_front(queue->list, id, ta, ts);
}

void queue_push_back(Queue *queue, char *id, int ta, int ts) {
        list_push_back(queue->list, id, ta, ts);
}

int queue_remove(Queue *queue, char *id) {
        int n = list_remove(queue->list, id);
        return n;
}

void queue_print_time(Queue *queue, int time) {
        list_print_time(queue->list, time);
}

Data *queue_find(Queue *queue, int time) {
        Data *ptr = list_find(queue->list, time);
        return ptr;
}
