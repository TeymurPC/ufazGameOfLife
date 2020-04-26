#include <stdio.h>
#include "print_to_console.h"

void print_board(struct board brd){
    for (int i = 0; i < BOARD_HEIGHT; i++)
    {
        for (int j = 0; j < BOARD_WIDTH; j++)
        {
            printf((brd.cells[i][j] ? "\033[07m  \033[m" : "  "));
        }
        printf("\n");
        
    }
    
}