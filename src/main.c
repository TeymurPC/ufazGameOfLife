#include <stdio.h>
#include <unistd.h>
#include "game.h"
#include "print_to_console.h"
#include "print_to_sdl.h"

int main(int argc, char const *argv[])
{
    struct board brd;
    new_random_board(&brd, CIRCULAR_BOARD);
    // print_board(brd, DEBUG_FALSE);
    print_SDL_init();
    print_SDL_print(brd);

    while(1){
        sleep(1);
        brd = new_board(brd);
        // print_board(brd, DEBUG_FALSE);
        print_SDL_print(brd);
    }

    return 0;
}
