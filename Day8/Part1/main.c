#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define DAYS 256
#define RESPAWN_DAYS 7
#define NEWSPAWN_DAYS 9
int main(int argc, char *argv[]){

    FILE* file = stdin;

    if (argc == 2)
    {
        file = fopen(argv[1], "r");
    }

    int count = 0;
    char* out1 = calloc(7, sizeof(char));
    char* out2 = calloc(7, sizeof(char));
    char* out3 = calloc(7, sizeof(char));
    char* out4 = calloc(7, sizeof(char));
    while (fscanf(file, "%*s %*s %*s %*s %*s %*s %*s %*s %*s %*s | %s %s %s %s\n", out1, out2, out3, out4) != EOF){
        switch(strlen(out1)){
            case 2:
            case 3:
            case 4:
            case 7: {
                count++;
                break;
            }
            default: {
                //do nothing
            }
        }
        switch(strlen(out2)){
            case 2:
            case 3:
            case 4:
            case 7: {
                count++;
                break;
            }
            default: {
                //do nothing
            }
        }
        switch(strlen(out3)){
            case 2:
            case 3:
            case 4:
            case 7: {
                count++;
                break;
            }
            default: {
                //do nothing
            }
        }
        switch(strlen(out4)){
            case 2:
            case 3:
            case 4:
            case 7: {
                count++;
                break;
            }
            default: {
                //do nothing
            }
        }
    }
    printf("ans: %d\n", count);
}
