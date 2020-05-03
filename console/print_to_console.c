#include "print_to_console.h"

void print_board(struct board brd, unsigned short debug){

    printf("\e[2J");
    printf("\e[0;0H");
    
    for (int i = 0; i < brd.height; i++)
    {
        for (int j = 0; j < brd.width; j++)
        {
            if(debug == DEBUG_FALSE)
                printf((brd.cells[i][j] == ALIVE_CELL ? "\033[07m  \e[0m" : "  "));
            else
                printf( (brd.cells[i][j] == ALIVE_CELL ? "\033[07m%d \e[0m" : "%d "),
                    (brd.circular_flag == CLIPPED_BOARD ? neighbours_clipped(brd, j, i) : neighbours_circular(brd, j, i)) );
        }
        printf("\n");
        
    }
       
}