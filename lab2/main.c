#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

char* get_str(){
        char buf[80] = {0};
        char* res = NULL;
        int len = 0;
        int n = 0;
        do{
                n = scanf("%80[^\n]",buf);
                if(n < 0){
                        if(!res) return NULL;
                } else if(n > 0){
                        int chunk_len = strlen(buf);
                        int str_len = len + chunk_len;
                        res = realloc(res,str_len + 1);
                        memcpy(res + len, buf, chunk_len);
                        len = str_len;
                } else{
                        scanf("%*c");
                }
        } while(n > 0);
        if(len > 0) res[len] = '\0';
        else res = calloc(1,sizeof(char));
        return res;
}


void input(List *list){
	list_push_back(list, "a", 1, 5);
	list_push_front(list, "*b", 2, 5);
	list_push_back(list, "c", 2, 3);
	list_push_front(list, "*d", 3, 1);
	list_push_back(list, "e", 5, 2);
	list_push_front(list, "*f", 10, 5);
	list_push_front(list, "*g", 10, 4);
	list_push_back(list, "h", 11, 1);
	list_push_back(list, "i", 15, 2);
	list_push_front(list, "*j", 15, 3);
}

void queue_process(List *list){
	int time = 1, t;
	while (list->head->n != 0){//происходит вывод состояния во время изменения очереди
//		list_print(list);
		printf("\n----- time: %d -----\n", time);
		list_print_time(list, time);
		Data *ptr = list_find(list, time);
		if (ptr != NULL) {
			t = ptr->ts;//время обслуживания первого в очереди
			list_remove(list, ptr->id);//удаление из очереди
			time += t;//изменение времени на время приема пациента у доктора
		} else time ++;// не нашлось пациентов в очереди в данный момент времени
	}
	printf("\n----- time: %d -----\nthe queue is empty\n", time);
}

int main(){
	char *s = NULL;
        List *list;
	list = list_init(list);
	input(list);
	queue_process(list);
//	list_delete(list);
	return 0;
}
