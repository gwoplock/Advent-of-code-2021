#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define DAYS 256
#define RESPAWN_DAYS 7
#define NEWSPAWN_DAYS 9

int arithSum(int a, int an){
    int movement = abs(a - an);
    return (movement * (2 + (movement - 1))) / 2;
}

int main(int argc, char *argv[]){

    FILE* file = stdin;

    if (argc == 2)
    {
        file = fopen(argv[1], "r");
    }

    int next;
    int pos[1000] = { 0 };
    int count = 0;
    while (fscanf(file, "%i,", &next) != EOF){
            pos[count] = next;
            count++;
    }

    int max = -1;
    for (int i = 0; i < count; i++) {
        if (pos[i] > max){
            max = pos[i];
        }
    }

    int cost[10000] = { 0 };
    for (int i = 0; i <= max; i++){
        for (int k = 0; k < count; k++){
            cost[i] += arithSum(i, pos[k]);
        }
    }

    int cheapest = INT_MAX;
    int cheapestLoc = 0;
    for (int i = 0; i <= max; i++) {
        if (cost[i] < cheapest){
            cheapest = cost[i];
            cheapestLoc = i;
        }
    }

    printf("ans: %d\n", cheapest);
}
