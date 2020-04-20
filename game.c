#include "game.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


void new_random_board(struct board *brd){
    time_t t;
    
    srand((unsigned) time(&t));

    for (int i = 0; i < BOARD_HEIGHT; i++)
    {
        for (int j = 0; j < BOARD_WIDTH; j++){
            struct cell cll;
            cll.x = j;
            cll.y = i;
            int rnd = rand()%10 > 8;
            cll.dead = rnd;
            brd->cells[i][j] = cll;
        }
    }
}

void print_board(struct board brd){
    for (int i = 0; i < BOARD_HEIGHT; i++)
    {
        for (int j = 0; j < BOARD_WIDTH; j++)
        {
            printf((brd.cells[i][j].dead ? "\033[07m  \033[m" : "  "));
        }
        printf("\n");
        
    }
    
}

