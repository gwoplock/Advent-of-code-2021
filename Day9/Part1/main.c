#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define DAYS 256
#define RESPAWN_DAYS 7
#define NEWSPAWN_DAYS 9

bool checkPos(int height[1000][1000], bool lowest[1000][1000], int col, int row, int colCnt, int rowCnt){
    bool marked = false;
    if (col != 0){
        if (height[col][row] > height[col-1][row])
        {
            marked = checkPos(height, lowest, col-1, row, colCnt, rowCnt);
        } else if (height[col][row] == height[col-1][row]) {
            marked = true;
        }
    }
    if (col != colCnt-1) {
        if (height[col][row] > height[col+1][row])
        {
            marked = checkPos(height, lowest, col+1, row, colCnt, rowCnt);
        } else if (height[col][row] == height[col+1][row]) {
            marked = true;
        }
    }
    if (row != 0 ){
        if (height[col][row] > height[col][row-1])
        {
            marked = checkPos(height, lowest, col, row-1, colCnt, rowCnt);
        } else if (height[col][row] == height[col][row-1]) {
            marked = true;
        }
    }
    if (row != rowCnt-1){
        if (height[col][row] > height[col][row+1])
        {
            marked = checkPos(height, lowest, col, row+1, colCnt, rowCnt);
        } else if (height[col][row] == height[col][row+1]) {
            marked = true;
        }
    }

    if (!marked)
    {
        lowest[col][row] = true;
        // printf("marked: col %d, row %d, height %d \n", col, row, height[col][row]);
    }

    return true;
}

int main(int argc, char *argv[]){

    FILE* file = stdin;

    if (argc == 2)
    {
        file = fopen(argv[1], "r");
    }

    char next;
    int height[1000][1000] = { 0 };
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
            height[colCnt][rowCnt] = next;
            colCnt++;
        }
    }

    printf("read map\n");

    bool lowest[1000][1000] = { 0 };
    for (int col = 0; col < lastColCnt; col++){
        for (int row = 0; row < rowCnt; row++){
            checkPos(height, lowest, col, row, lastColCnt, rowCnt);
        }
    }

    printf("found lows \n");

    int sum = 0;
    for (int col = 0; col < lastColCnt; col++){
        for (int row = 0; row < rowCnt; row++){
            if (lowest[col][row]){
                sum += 1 + height[col][row];
                printf("added low @ col %d, row %d as %d\n", col, row, 1 + height[col][row]);
            }
        }
    }
    printf("ans: %d\n", sum);
}
