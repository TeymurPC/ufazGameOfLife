#ifndef PRINT_TO_CONSOLE_H
#define PRINT_TO_CONSOLE_H

    #include <stdio.h>
    #include "../game/game.h"
    #define DEBUG_TRUE 1
    #define DEBUG_FALSE 0
    void print_board(struct board brd, unsigned short debug);
#endif