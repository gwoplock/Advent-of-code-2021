#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int getPoints(char c){
    switch (c){
        case ')':{
            return 3;
            break;
        }
        case ']':{
            return 57;
            break;
        }
        case '}':{
            return 1197;
            break;
        }
        case '>':{
            return 25137;
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
    int sum = 0;
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
                    sum += getPoints(in);
                } else{
                    stackTopIdx--;
                    if (getCloseFor(stack[stackTopIdx]) != in){
                        foundErr = true;
                        sum += getPoints(in);
                    }
                }
                break;
            }
            case '\n':{
                foundErr = false;
                break;
            }
            default:{
                printf("unknown char %c\n", in);
            }
        }
    }
    printf("ans: %d\n", sum);
}