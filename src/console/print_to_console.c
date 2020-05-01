#include "print_to_console.h"

void print_board(struct board brd){

    printf("\e[2J");
    printf("\e[0;0H");
    
    for (int i = 0; i < BOARD_HEIGHT; i++)
    {
        for (int j = 0; j < BOARD_WIDTH; j++)
        {
            printf((brd.cells[i][j] == ALIVE_CELL ? "\033[07m  \e[0m" : "  "));
        }
        printf("\n");
        
    }

        
}