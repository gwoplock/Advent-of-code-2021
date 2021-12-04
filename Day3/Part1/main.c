#include <stdio.h>

typedef struct {
    int zeros;
    int ones;
} counts_t;

#define WIDTH 12

int main(int argc, char *argv[]){

    FILE* file = stdin;

    if (argc == 2)
    {
        file = fopen(argv[1], "r");
    }

    counts_t counts[WIDTH] = { {0, 0} };
    int pos = 0;
    char val;
    while ((val= fgetc(file)) != EOF)
    {
        printf("read at pos %d as %c\n", pos, val);
        switch (val){
            case '0': {
                counts[pos].zeros++;
                pos++;
                break;
            }
            case '1': {
                counts[pos].ones++;
                pos++;
                break;
            }
            case '\n': {
                pos = 0;
                break;
            }
            default: {
                printf("unexpected char\n");
                break;
            }
        }
    }

    int gamma = 0;
    int epsilon = 0;
    for (int i = 0; i < WIDTH; i++){
        if (counts[i].zeros != 0 && counts[i].ones != 0){
            printf("pos[%d] 0: %d 1: %d \n", i, counts[i].zeros, counts[i].ones);
            gamma = gamma << 1;
            epsilon = epsilon << 1;
            if (counts[i].zeros > counts[i].ones){
                epsilon |= 0b1;
                //do nothing for gamma, zero already there
            } else if (counts[i].zeros < counts[i].ones){
                gamma |= 0b1;
                //do nothing for epsilon, zero already there
            }
        }
    }
    printf("gamma: %d, epsilon: %d, ans: %d\n", gamma, epsilon, gamma*epsilon);
}
