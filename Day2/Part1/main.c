#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

    FILE* file = stdin;

    if (argc == 2)
    {
        file = fopen(argv[1], "r");
    }

    int depth = 0, forward = 0, val;
    char* dir = malloc(100);
    while ( fscanf(file, "%s %d\n", dir, &val) != EOF)
    {
        printf("got dir: %s, val:%d\n", dir, val);
        if (strcmp("forward", dir) == 0) {
            forward += val;
        } else if (strcmp("down", dir) == 0) {
            depth += val;
        } else if (strcmp("up", dir) == 0) {
            depth -= val;
        } else {
            printf("unkonwn dir");
        }
    }
    printf("depth: %d, fwd: %d, ans: %d\n", depth, forward, depth * forward);
}
