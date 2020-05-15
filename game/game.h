#ifndef GAME_H
#define GAME_H

    #include <stdlib.h>
    #include <stdio.h>
    #include <time.h>
    


    #define BOARD_HEIGHT 50
    #define BOARD_WIDTH 50
    #define DEAD_CELL 0
    #define ALIVE_CELL 1
    #define CIRCULAR_BOARD 1
    #define CLIPPED_BOARD 0


    struct board{
        unsigned short **cells;
        unsigned short circular_flag;
        int height;
        int width;
    };


    void new_random_board(struct board *brd);

    int neighbours_clipped(struct board brd, int x, int y);
    int neighbours_circular(struct board brd, int x, int y);
    struct board next_board(struct board brd);
    void init_board(struct board *brd, int width, int height, unsigned short circular_flag);
    void destroy_board(struct board *brd);


    
    
#endif

