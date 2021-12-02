#include <stdio.h>

int main(){
    int prev_depth = -1, depth, count = 0;
    while ( scanf("%i\n", &depth) != EOF)
    {
        if (prev_depth == -1)
        {
            prev_depth = depth;
            continue;
        }

        if (depth > prev_depth)
        {
            count++;
        }
        prev_depth = depth;
    }
    printf("%i", count);
}
