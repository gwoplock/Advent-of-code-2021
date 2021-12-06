#include <stdio.h>
#include <stdlib.h>

#define DAYS 80
#define RESPAWN_DAYS 7
#define NEWSPAWN_DAYS 9
int main(int argc, char *argv[]){

    FILE* file = stdin;

    if (argc == 2)
    {
        file = fopen(argv[1], "r");
    }

    char next;
    long long int sim[DAYS+12] = { 0 };
    while ((next = fgetc(file)) != EOF){
        if (next == '\n' || next == ','){
            continue;
        } else {
            next -= 0x30;
            sim[next]++;
        }
    }

    printf("loaded \n");

    int k = 0;
    for (int i = 0; i < DAYS; i++){
        sim[k + RESPAWN_DAYS] += sim[k];
        sim[k + NEWSPAWN_DAYS] += sim[k];

        k++;
    }

    printf("simed\n");

    long long int count = 0;
    for (int i = 0; i <= NEWSPAWN_DAYS; i++){
        count += sim[k + i];
    }

    printf("ans: %lld\n", count);
}
