#include <stdio.h>
#include <stdlib.h>

typedef struct llNode_s {
    struct llNode_s *next;
    struct llNode_s *prev;
    int data;
} llNode_t;

void llInsert(llNode_t **head, llNode_t **tail, int data){
    llNode_t* node = malloc(sizeof(llNode_t));
    if (*head == NULL){
        *head = node;
    }

    if (*tail != NULL){
        (*tail)->next = node;
    }
    node->prev = *tail;
    node->data = data;
    *tail = node;
}

int main(int argc, char *argv[]){

    FILE* file = stdin;

    if (argc == 2)
    {
        file = fopen(argv[1], "r");
    }

    char next;
    llNode_t *head = NULL;
    llNode_t *tail = NULL;

    while ((next = fgetc(file)) != EOF){
        if (next == '\n' || next == ','){
            continue;
        } else {
            next -= 0x30;
            llInsert(&head, &tail, next);
        }
    }

    printf("loaded \n");

    for (int i = 0; i < 80; i++){
        llNode_t *node = head;
        while (node != NULL){
            if (node->data == 0)
            {
                node->data = 6;
                llInsert(&head, &tail, 9);
            } else {
                node->data--;
            }
        }
    }

    printf("simed\n");

    long long int count = 0;
    for (llNode_t *i = head; i != NULL; i = i->next){
        count++;
    }

    printf("ans: %lld\n", count);
}
