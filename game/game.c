#include "game.h"
#include <stdio.h>


int neighbours_clipped(struct board brd, int x,int y){

    int nb_neighbours=0;

    for(int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++)
        {
            if ( !(y+i<0 || x+j<0 || y+i >= brd.height || x+j >= brd.width) ){
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
                y_check = brd.height - 1;
            if (x+j<0)
                x_check = brd.width - 1;
            if (y+i >= brd.height)
                y_check = 0;
            if (x+j >= brd.width)
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


void new_random_board(struct board *brd){
    time_t t;
    
    srand((unsigned) time(&t));

    

    for (int i = 0; i < brd->height; i++)
    {
        for (int j = 0; j < brd->width; j++){
            if (rand()%10 > 7){
                brd->cells[i][j] = ALIVE_CELL;
            }else{
                brd->cells[i][j] = DEAD_CELL;
            }
        }
    }
}

struct board next_board(struct board brd){
    struct board next_board;
    init_board(&next_board, brd.width, brd.height, brd.circular_flag);
    // next_board.circular_flag = brd.circular_flag;
    for (int i = 0; i< brd.height; i++){
        for (int j = 0; j < brd.width; j++){
            int nghbrs = 0;
            if (brd.circular_flag == CLIPPED_BOARD){
                nghbrs = neighbours_clipped(brd, j, i);
            }else{
                nghbrs = neighbours_circular(brd, j, i);
            }


            if (brd.cells[i][j] == ALIVE_CELL){
                if (nghbrs == 2 || nghbrs == 3){
                    next_board.cells[i][j] = ALIVE_CELL;
                }else{
                    next_board.cells[i][j] = DEAD_CELL;
                }
            }else{
                if (nghbrs == 3){
                    next_board.cells[i][j] = ALIVE_CELL;
                }else{
                    next_board.cells[i][j] = DEAD_CELL;
                }
            }
        }
    }

    return next_board;
}

void init_board(struct board *brd, int width, int height, unsigned short circular_flag){
    brd->circular_flag = circular_flag;

    brd->height = height;
    brd->width = width;

    brd->cells = malloc(brd->height * sizeof(unsigned short *));
    for(int i = 0; i < brd->height; i++){
        brd->cells[i] = malloc(brd->width * sizeof(unsigned short));
    }
}

void destroy_board(struct board *brd){
    for (int i = 0; i < brd->height; i++){
        free(brd->cells[i]);
    }
    free(brd->cells);
}