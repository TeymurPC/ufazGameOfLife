#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "print_to_console.h"

int main(int argc, char const *argv[])
{
    struct board brd;
    new_random_board(&brd);

    // int nb_neighbours = neighbours(brd, 3,3);
    // printf("%d\n",nb_neighbours);

    print_board(brd);
    
    return 0;
}
