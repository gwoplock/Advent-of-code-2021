#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>

#define DAYS 256
#define RESPAWN_DAYS 7
#define NEWSPAWN_DAYS 9
int main(int argc, char *argv[]){

    FILE* file = stdin;

    if (argc == 2)
    {
        file = fopen(argv[1], "r");
    }

    int sum = 0;
    char* out[4];
    out[0] = calloc(7, sizeof(char));
    out[1] = calloc(7, sizeof(char));
    out[2] = calloc(7, sizeof(char));
    out[3] = calloc(7, sizeof(char));
    char* ex[10];
    ex[0] = calloc(7, sizeof(char));
    ex[1] = calloc(7, sizeof(char));
    ex[2] = calloc(7, sizeof(char));
    ex[3] = calloc(7, sizeof(char));
    ex[4] = calloc(7, sizeof(char));
    ex[5] = calloc(7, sizeof(char));
    ex[6] = calloc(7, sizeof(char));
    ex[7] = calloc(7, sizeof(char));
    ex[8] = calloc(7, sizeof(char));
    ex[9] = calloc(7, sizeof(char));

    while (fscanf(file, "%s %s %s %s %s %s %s %s %s %s | %s %s %s %s\n", ex[0], ex[1],ex[2],ex[3],ex[4],ex[5],ex[6],ex[7],ex[8],ex[9],
        out[0], out[1], out[2], out[3]) != EOF)
    {
        int exOf[10] = { -1 };
        int skipped = 10;
        while (skipped != 0)
        {
            for (int i = 0; i < 10; i++) {
                switch (strlen(strlen(ex[i])))
                {
                    case 2:{
                        if (exOf[1] == -1){
                            exOf[1] = i;
                            skipped--;
                        }
                        break;
                    }
                    case 3: {
                        if (exOf[7] == -1){
                            exOf[7] = i;
                            skipped--;
                        }
                        break;
                    }
                    case 4: {
                        if (exOf[4] == -1){
                            exOf[4] = i;
                            skipped--;
                        }
                        break;
                    }
                    case 5: {
                        break;
                    }
                    case 6: {
                        if (exOf[6] == -1 && exOf[1] != -1 && exOf[7] != -1)
                        {
                            char extraSeg = 0;
                            for (int i = 0; i < strlen(ex[exOf[7]]); i++){
                                bool found = false;
                                for (int k = 0; k < strlen(ex[exOf[1]]); k++){
                                    if (ex[exOf[7]][i] == ex[exOf[1]][k])
                                    {
                                        found = true;
                                    }
                                }

                                if (!found){
                                    extraSeg = ex[exOf[7]][i];
                                    break;
                                }
                            }
                        }
                        break;
                    }
                    case 7: {
                        if (exOf[8] == -1) {
                            exOf[8] = i;
                            skipped--;
                        }
                        break;
                    }
                }
            }
        }
    }
    printf("ans: %d\n", sum);
}
