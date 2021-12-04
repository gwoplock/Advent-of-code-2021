#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int num;
    bool marked;
} bingoNumber_t;

int main(int argc, char *argv[]){

    FILE* file = stdin;

    if (argc == 2)
    {
        file = fopen(argv[1], "r");
    }

    int marked[10000];
    int markedCount = 0;
    while (fscanf(file, "%i", &marked[markedCount]) != EOF)
    {
        markedCount++;
        if (fgetc(file) == '\n')
        {
            break;
        }
    }

    printf("mkd_cnt: %d\n", markedCount);

    bingoNumber_t boards[1000][5][5];
    int boardCount = 0;
    while(fgetc(file) != EOF)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int k = 0; k < 5; k++){
                fscanf(file, "%i", &boards[boardCount][i][k].num);
                while(fgetc(file) == ' '){
                    //eat spaces
                }
                fseek(file, -1, SEEK_CUR);
            }
            fgetc(file); //eat new line
        }
        boardCount++;
    }

    printf("board_cnt: %i\n", boardCount);
    bool boardWon[1000] = { false };
    for (int i = 0; i < markedCount; i++)
    {
        for (int k = 0; k < boardCount; k++)
        {
            for (int x = 0; x < 5; x++)
            {
                for (int y = 0; y < 5; y++)
                {
                    if (boards[k][x][y].num == marked[i])
                    {
                        boards[k][x][y].marked  = true;
                        bool win =true;
                        for (int j = 0; j < 5; j++)
                        {
                            if (!boards[k][j][y].marked){
                                win = false;
                                break;
                            }
                        }

                        if (win == true)
                        {
                            if (boardWon[k])
                            {
                                continue;
                            }

                            int sum = 0;
                            for (int a = 0; a < 5; a++)
                            {
                                for (int b =0; b <5; b++)
                                {
                                    if (!boards[k][a][b].marked)
                                    {
                                        sum += boards[k][a][b].num;
                                    }
                                }
                            }
                            printf("ans: %d\n", sum*marked[i]);
                            boardWon[k] = true;
                        }

                        win = true;
                        for (int j = 0; j < 5; j++)
                        {
                            if (!boards[k][x][j].marked){
                                win = false;
                                break;
                            }
                        }

                        if (win == true)
                        {
                            if (boardWon[k])
                            {
                                continue;
                            }

                            int sum = 0;
                            for (int a = 0; a < 5; a++)
                            {
                                for (int b =0; b <5; b++)
                                {
                                    if (!boards[k][a][b].marked)
                                    {
                                        sum += boards[k][a][b].num;
                                    }
                                }
                            }
                            printf("ans: %d\n", sum*marked[i]);
                            boardWon[k] = true;
                        }
                    }
                }
            }
        }
    }
}
