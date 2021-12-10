#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int intcmp(const void *aa, const void *bb)
{
    const long long int *a = aa, *b = bb;
    return (*a < *b) ? -1 : (*a > *b);
}

int getPoints(char c){
    switch (c){
        case ')':{
            return 1;
            break;
        }
        case ']':{
            return 2;
            break;
        }
        case '}':{
            return 3;
            break;
        }
        case '>':{
            return 4;
            break;
        }
    }
}

char getCloseFor(char c){
    switch (c){
        case '(':{
            return ')';
            break;
        }
        case '[':{
            return ']';
            break;
        }
        case '{':{
            return '}';
            break;
        }
        case '<':{
            return '>';
            break;
        }
    }
}

int main(int argc, char *argv[]){

    FILE* file = stdin;

    if (argc == 2)
    {
        file = fopen(argv[1], "r");
    }

    char in;
    char stack[1000] = { 0 };
    int stackTopIdx = 0;
    long long int sum[1000] = { 0 };
    int line = 0;
    bool foundErr = false;
    while ((in = fgetc(file)) != EOF){
        if (foundErr && in != '\n'){
            continue;
        }
        switch (in){
            case '(':
            case '[':
            case '{':
            case '<':{
                stack[stackTopIdx] = in;
                stackTopIdx++;
                break;
            }
            case ')':
            case ']':
            case '}':
            case '>':{
                if (stackTopIdx == 0){
                    foundErr = true;
                    // sum += getPoints(in);
                } else{
                    stackTopIdx--;
                    if (getCloseFor(stack[stackTopIdx]) != in){
                        foundErr = true;
                        // sum += getPoints(in);
                    } else {
                        stack[stackTopIdx] = 0;
                    }
                }
                break;
            }
            case '\n':{
                
                for (stackTopIdx--; stackTopIdx >= 0; stackTopIdx--){
                    if (!foundErr){
                        sum[line] *= 5;
                        sum[line] += getPoints(getCloseFor(stack[stackTopIdx]));
                    }
                    stack[stackTopIdx] = 0;
                }
                
                if (!foundErr){
                    line++;
                }

                stackTopIdx = 0;
                foundErr = false;
                break;
            }
            default:{
                printf("unknown char %c\n", in);
            }
        }
    }

    qsort(sum, line, sizeof(long long int), intcmp);


    printf("ans: %lld\n", sum[(line)/2]);
}