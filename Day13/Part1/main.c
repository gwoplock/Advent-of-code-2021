#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

void printArr(bool dots[2000][2000], int maxX, int maxY){
    printf("\n\n\n");

    for (int y = 0; y <= maxY; y++){
        for (int x = 0 ; x <= maxX; x++){
            if (dots[x][y]){
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }

    printf("\n\n\n");
}

int countDots(bool dots[2000][2000], int maxX, int maxY){
    int count = 0;
    for (int y = 0; y <= maxY; y++){
        for (int x = 0; x <= maxX; x++){
            if (dots[x][y]){
                count++;
            }
        }
    }
    return count;
}

int main(int argc, char *argv[]){

    FILE* file = stdin;

    if (argc == 2)
    {
        file = fopen(argv[1], "r");
    }

    bool dots[2000][2000] = { false };
    int x, y;
    char n;
    int maxX = 0, maxY = 0;
    while (fscanf(file, "%i,%i\n", &x, &y) != EOF) {
        dots[x][y] = true;

        if (x > maxX){
            maxX = x;
        }
        if (y > maxY){
            maxY = y;
        }

        if ((n = fgetc(file)) == 'f') {
            fseek(file, -1, SEEK_CUR);
            break;
        } else {
            fseek(file, -1, SEEK_CUR);
        }
    }

    printf("read Dots\n");
    char direct =0;
    int line =0;
    while (fscanf(file, "fold along %c=%i\n", &direct, &line) != EOF){
        // printArr(dots, maxX, maxY);
        printf("current Count: %d\n", countDots(dots, maxX, maxY));
        printf("fold along %c axis @ %i\n", direct, line);

        if (direct == 'y'){
            for (int y = line; y <= maxY; y++){
                for (int x = 0; x <= maxX; x++){
                    if (dots[x][y]){
                        dots[x][line-(y-line)] = true;
                        dots[x][y] = false;
                    }
                }
            }
        } else if (direct == 'x'){
            for (int x = line; x <= maxX; x++){
                for (int y= 0; y <= maxY; y++){
                    if (dots[x][y]){
                        dots[line-(x-line)][y] = true;
                        dots[x][y] = false;
                    }
                }
            }
        }
    }

    printf("done folding\n");
    // printArr(dots, maxX, maxY);
    printf("current Count: %d\n", countDots(dots, maxX, maxY));
}
