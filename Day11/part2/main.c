#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>


#define FLASH_LEVEL 9
#define STEP_COUNT 100
int main(int argc, char *argv[]){

    FILE* file = stdin;

    if (argc == 2)
    {
        file = fopen(argv[1], "r");
    }

    char next;
    int levels[1000][1000] = { 0 };
    int colCnt = 0;
    int lastColCnt;
    int rowCnt = 0;
     while ((next = fgetc(file)) != EOF){
        if (next == '\n'){
            lastColCnt = colCnt;
            colCnt = 0;
            rowCnt++;
        } else {
            next -= 0x30;
            levels[colCnt][rowCnt] = next;
            colCnt++;
        }
    }

    printf("loaded\n");

    int flashCnt = 0;
    bool allFlashed = false;
    int stepCnt = 0;
    while (!allFlashed){
        bool flashed[1000][1000] = { false };
        int oldFlashCnt = flashCnt;
        for (int col = 0; col < lastColCnt; col++){
            for (int row = 0; row < rowCnt; row++){
                levels[col][row]++;
            }
        }
        do{
            oldFlashCnt = flashCnt;
            for (int col = 0; col < lastColCnt; col++){
                for (int row = 0; row < rowCnt; row++){
                    if (levels[col][row] > FLASH_LEVEL && !flashed[col][row]){
                        flashed[col][row] = true;
                        flashCnt++;
                        levels[col][row] = 0;
                        levels[col+1][row]++;
                        levels[col+1][row+1]++;
                        levels[col+1][row-1]++;
                        levels[col-1][row]++;
                        levels[col-1][row+1]++;
                        levels[col-1][row-1]++;
                        levels[col][row+1]++;
                        levels[col][row-1]++;
                    }
                }
            }
        } while (flashCnt != oldFlashCnt);

        allFlashed = true;
        for (int col = 0; col < lastColCnt; col++){
            for (int row = 0; row < rowCnt; row++){
                if (flashed[col][row]){
                    levels[col][row] = 0;
                } else {
                    allFlashed = false;
                }
            }
        }
        stepCnt++;
        printf("step %d done\n", stepCnt);
    }
    printf("ans: %d\n", stepCnt);
}
