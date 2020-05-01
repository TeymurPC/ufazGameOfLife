#include "game.h"


int neighbours(struct board brd, int x,int y){

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


void new_random_board(struct board *brd){
    time_t t;
    
    srand((unsigned) time(&t));

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
    for (int i = 0; i< BOARD_HEIGHT; i++){
        for (int j = 0; j < BOARD_WIDTH; j++){
            int nghbrs = neighbours(brd, j, i);
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