#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

List *list_init(List *list) {
	Item *ptr = (Item *) calloc(1, sizeof(Item));
	ptr->n = 0;
	ptr->prev = NULL;
	ptr->next = NULL;
        list->tail = ptr;
	list->head = ptr;
	return list;
}

void list_delete(List *list) {
	Item *ptr = list->head;
        Item *next = NULL;
	while (ptr){
		next = ptr->next;
                for (int i = 0; i < 5; i++)
		{
			free(ptr->data[i]);
		}
		ptr->data;
		free(ptr);
		ptr = next;
	}
}

int list_push_back(List *list, char *id, int ta, int ts) {
	Data *ptr = (Data *) malloc(sizeof(Data));
	for (int i = 0; i < 2; i++) {
	        ptr->id[i] = id[i];
	}
	ptr->id[2] = '\0';
	ptr->ta = ta;
	ptr->ts = ts;
	int n = list->tail->n;
	if (n == 5){//создание нового блока из 5 человек
		Item *tmp = (Item*) malloc(sizeof(Item));
		tmp->next = NULL;
		tmp->prev = list->tail;
                tmp->n = 0;
		list->tail->next = tmp;
                if (list->tail->prev == NULL) {
                        list->head = list->tail;
                }
		list->tail = tmp;
	}
	list->tail->data[list->tail->n] = ptr;
        list->tail->n++;
	return 0;
}

int list_push_front(List *list, char *id, int ta, int ts) {
        Data *ptr = (Data *) malloc(sizeof(Data));
        for (int i = 0; i < 2; i++) {
                ptr->id[i] = id[i];
        }
        ptr->id[2] = '\0';
        ptr->ta = ta;
        ptr->ts = ts;
        int n = list->head->n;
        if (n == 5 || list->head->data[0]->id[0] != '*'){//создание нового блока из 5 человек
                Item *tmp = (Item*) malloc(sizeof(Item));
                tmp->prev = NULL;
                tmp->next = list->head;
                tmp->n = 0;
                list->head->prev = tmp;
                if (list->head->next == NULL) {
                        list->tail = list->head;
                }
                list->head = tmp;
        }
        list->head->data[list->head->n] = ptr;
        list->head->n++;
        return 0;
}

void list_print(List *list) {
	Item *ptr = list->head;
	int n;
	while (ptr) {
		n = ptr->n;
		for (int i = 0; i < n; i++)
			printf("%d - %s/%d/%d ", i, ptr->data[i]->id, ptr->data[i]->ta, ptr->data[i]->ts);
		ptr = ptr->next;
	}
	printf("\n");
}

void list_print_back(List *list) {
	Item *ptr = list->tail;
	int n;
        while (ptr) {
		n = ptr->n;
                for (int i = n-1; i >= 0; i--)
			printf("%s/%d/%d ", ptr->data[i]->id, ptr->data[i]->ta, ptr->data[i]->ts);
		ptr = ptr->prev;
	}
	printf("\n");
}

int list_remove(List *list, char *id) {
	Item *ptr = list->head;
	while (ptr) {
		for (int i = 0; i < ptr->n; i++) {
			if (ptr->data[i]->id == id) {
				for (int j = i; j < ptr->n - 1; j++) {
					ptr->data[j] = ptr->data[j+1];
				}
				ptr->n --;
				ptr->data[ptr->n] = NULL;
				if (ptr->n == 0) {
					if (ptr != list->head && ptr != list->tail) {
						Item *ptr_prev = ptr->prev;
						Item *ptr_next = ptr->next;
						ptr_next->prev = ptr->prev;
						ptr_prev->next = ptr->next;
						free(ptr);
					} else if (ptr == list->head) {
							if (list->head->next) list->head = list->head->next;
							list->head->prev = NULL;
							free(ptr);
					       } else   {//ptr == list->tail
								 if (list->tail->prev) list->tail = list->tail->prev;
							         list->tail->next = NULL;
								 free(ptr);
							}
				}
				return 0;//пациент удален из очереди
			}
		}
		ptr = ptr->next;
	}
	return 1;//нет такого пациента
}

void list_print_time(List *list, int time) {
	Item *ptr = list->head;
	int n, flag = 0;
        while (ptr && flag == 0) {
                n = ptr->n;
                for (int i = 0; i < n; i++)
                        if (ptr->data[i]->ta <= time) printf("%s ", ptr->data[i]->id);
			else if (ptr->data[i]->id[0] != '*') flag = 1;
                ptr = ptr->next;
        }
        printf("\n");
}

Data *list_find(List *list, int time) {// с пробелами
	Item *ptr = list->head;
        while (ptr) {
                for (int i = 0; i < ptr->n; i++) {
                        if (ptr->data[i]->ta <= time) {
                        	return ptr->data[i];
                        }
                }
                ptr = ptr->next;
        }
        return 0;//нет такого пациента
}
