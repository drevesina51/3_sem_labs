#ifndef LIST_H
#define LIST_H

typedef struct Data {//данные пациента
    char id[3];//идентификатор
    int ta;//время появления
    int ts;//время обслуживания
} Data;

typedef struct Item {
    Data *data[5];//массив из 5 человек
    int n;//количество человек в данном массиве
    struct Item *next;
    struct Item *prev;
} Item;

typedef struct List {
    Item *head;
    Item *tail;
} List;

List *list_init(List *list);
void list_print_back(List *list);//вывод списка с конца
void list_print(List *list);//вывод списка
void list_pop_front(List *list, Data *data);//удаление элемента из начала списка
int list_push_back(List *list, char *id, int ta, int ts);//добавление элемента в конец списка
int list_push_front(List *list, char *id, int ta, int ts);//добавление элемента в начало списка
void list_delete(List *list);//удаление списка
int list_remove(List *list, char *id);//удаление элемента списка по id
void list_print_time(List *list, int time);//вывод очереди для данного времени
Data *list_find(List *list, int time);//указатель на первый элемент очереди, подходящий по времени

#endif //LIST_H
