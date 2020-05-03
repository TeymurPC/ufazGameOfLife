#include <unistd.h>
#include <SDL2/SDL.h>
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

    int quit = 0;
    SDL_Event e;

    while(!quit){
        sleep(1);
        brd = new_board(brd);
        // print_board(brd, DEBUG_FALSE);
        print_SDL_print(brd);
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                quit = 1;
            }
        }
    }

    print_SDL_close();

    return 0;
}
