#include "game.h"


int neighbours_clipped(struct board brd, int x,int y){

    int nb_neighbours=0;

    for(int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++)
        {
            if ( !(y+i<0 || x+j<0 || y+i >= BOARD_HEIGHT || x+j >= BOARD_WIDTH) ){
                if(brd.cells[y+i][x+j] == ALIVE_CELL)
                {
                    if(!(i == 0 && j == 0)){
                        nb_neighbours++;
                    }
                
                }
            }
        }

    }
    return nb_neighbours;

}

int neighbours_circular(struct board brd, int x, int y){
    int nb_neighbours=0;

    for(int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++)
        {
            
            int y_check = y+i;
            int x_check = x+j;

            if (y+i<0)
                y_check = BOARD_HEIGHT - 1;
            if (x+j<0)
                x_check = BOARD_WIDTH - 1;
            if (y+i >= BOARD_HEIGHT)
                y_check = 0;
            if (x+j >= BOARD_WIDTH)
                x_check = 0;

            if(brd.cells[y_check][x_check] == ALIVE_CELL)
            {
                if(!(i == 0 && j == 0)){
                    nb_neighbours++;
                }
            
            }
        }

    }
    return nb_neighbours;
}


void new_random_board(struct board *brd, unsigned short circular_flag){
    time_t t;
    
    srand((unsigned) time(&t));

    brd->circular_flag = circular_flag;

    for (int i = 0; i < BOARD_HEIGHT; i++)
    {
        for (int j = 0; j < BOARD_WIDTH; j++){
            
            if (rand()%10 > 7){
                brd->cells[i][j] = ALIVE_CELL;
            }else{
                brd->cells[i][j] = DEAD_CELL;
            }
        }
    }
}

struct board new_board(struct board brd){
    struct board new_board;
    new_board.circular_flag = brd.circular_flag;
    for (int i = 0; i< BOARD_HEIGHT; i++){
        for (int j = 0; j < BOARD_WIDTH; j++){
            int nghbrs = 0;
            if (brd.circular_flag == CLIPPED_BOARD){
                nghbrs = neighbours_clipped(brd, j, i);
            }else{
                nghbrs = neighbours_circular(brd, j, i);
            }


            if (brd.cells[i][j] == ALIVE_CELL){
                if (nghbrs == 2 || nghbrs == 3){
                    new_board.cells[i][j] = ALIVE_CELL;
                }else{
                    new_board.cells[i][j] = DEAD_CELL;
                }
            }else{
                if (nghbrs == 3){
                    new_board.cells[i][j] = ALIVE_CELL;
                }else{
                    new_board.cells[i][j] = DEAD_CELL;
                }
            }
        }
    }

    return new_board;
}