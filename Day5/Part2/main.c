#include <stdio.h>

int min(int a, int b)
{
    return a > b ? b : a;
}

int max(int a, int b)
{
    return a < b ? b : a;
}

int main(int argc, char *argv[]){

    FILE* file = stdin;

    if (argc == 2)
    {
        file = fopen(argv[1], "r");
    }

    int map[1000][1000] = { 0 };
    int x1, x2, y1, y2;
    while (fscanf(file, "%i,%i -> %i,%i\n", &x1, &y1, &x2, &y2) != EOF)
    {
        if (y1 == y2){
            for (int i = min(x1, x2); i <= max(x2, x1); i++){
                map[i][y1]++;
            }
        } else if (x1 == x2){
            for (int i = min(y1, y2); i <= max(y2, y1); i++){
                map[x1][i]++;
            }
        } else {
            for (int i = 0; i <= (max(x1, x2) - min(x1,x2)); i++){
                if (x1 < x2){
                    if (y1 < y2){
                        map[x1+i][y1+i]++;
                    } else {
                        map[x1+i][y1-i]++;
                    }
                } else {
                    if (y1 < y2){
                        map[x1-i][y1+i]++;
                    } else {
                        map[x1-i][y1-i]++;
                    }
                }
            }
        }
    }

    int count  = 0;
    for (int x = 0; x < 1000; x++){
        for (int y = 0; y < 1000; y++){
            if (map[x][y] >= 2)
            {
                count++;
            }
        }
    }
    printf("ans: %d\n", count);
}
