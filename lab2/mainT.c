#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "queue.h"
#define min(x, y) (x)<=(y)?(x):(y)

char* get_str(){
        char buf[81] = {0};
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


int input(Queue *queue, char *s){
        int len, i, num, ta, ts, n;
        char *ptr = s;
        char pt[] = " \t";
        char id[3];
        char a[11];
        do {
                num = strspn (ptr, pt);
                ptr += num;
                if (*ptr != '\0') {
                        len = strcspn (ptr, "/");
                        if (len == 0  || len == strlen(ptr))
                                return 1;
                        n = min(len, 2);
                        for (i = 0; i < n; i++)
                                id[i] = ptr[i];
                        id[n] = '\0';
                        ptr += len + 1;
                        if (*ptr == '\0')
                                return 1;
                              //ta
                        len = strcspn (ptr, "/");
                        if (len == 0 || len == strlen(ptr))
                                return 1;
                        n = min(len, 10);
                        for (i = 0; i < n; i++)
                                a[i] = ptr[i];
                        a[n] = '\0';
                        ta = atoi(a);
                        if (ta == 0)
                                return 1;
                        ptr += len + 1;
                        if (*ptr == '\0')
                                return 1;
            //ts
                        len = strcspn (ptr, pt);
                        if (len == 0)
                                return 1;
                        n = min(len, 10);
                        for (i = 0; i < n; i++)
                                a[i] = ptr[i];
                        a[n] = '\0';
                        ts = atoi(a);
                        if (ts == 0)
                                return 1;
                        ptr += len;
                }
                if (id[0]!= '*') queue_push_back(queue, id, ta, ts);
                else queue_push_front(queue, id, ta, ts);
        } while (*ptr != '\0');
    return 0;
}

void queue_process(Queue *queue){
        int time = 1, t;
        while (queue->list->head->n != 0){//происходит вывод состояния во время изменения очереди
                printf("\n----- time: %d -----\n", time);
                queue_print_time(queue, time);
                Data *ptr = queue_find(queue, time);
                if (ptr != NULL) {
                        t = ptr->ts;//время обслуживания первого в очереди
                        queue_remove(queue, ptr->id);//удаление из очереди
                        time += t;//изменение времени на время приема пациента у доктора
                } else while (queue_find(queue, time) == 0) time ++;// не нашлось пациентов в очереди в данный момент времени
        }
        printf("\n----- time: %d -----\nthe queue is empty\n", time);
}

int main(){
        char *s = NULL;
        Queue *queue = (Queue *) calloc(1, sizeof(Queue));
        queue = queue_new(queue);
        printf("Please, input data id/ta/ts:\n");
        do {
                s = get_str();
                if (s)  {
                                if (input(queue, s) == 1) {
                                        printf("Data is in incorrect form!\n");
                                }
                                free(s);
                        }
           } while(s);
        queue_process(queue);
//      free(queue);
        return 0;
}
