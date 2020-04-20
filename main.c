#include <stdio.h>
#include <stdlib.h>
#include "game.h"

int main(int argc, char const *argv[])
{
    struct board brd;
    new_random_board(&brd);

    print_board(brd);
    
    return 0;
}
