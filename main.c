#include <unistd.h>
// #include <SDL2/SDL.h>
#include <signal.h>
#include "game/game.h"
#include "console/print_to_console.h"

// #include "print_to_sdl.h"

int quit = 0;

void quit_signal(){
    quit = 1;
}
int main(int argc, char const *argv[])
{
    struct board brd;
    init_board(&brd, 60, 50, CIRCULAR_BOARD);
    new_random_board(&brd);
    print_board(brd, DEBUG_FALSE);
    // print_SDL_init();
    // print_SDL_print(brd);

    // SDL_Event e;
    signal(SIGINT, quit_signal);

    while(!quit){
        sleep(1);
        brd = next_board(brd);
        print_board(brd, DEBUG_FALSE);
        // print_SDL_print(brd);
        // while (SDL_PollEvent(&e)){
        //     if (e.type == SDL_QUIT){
        //         quit = 1;
        //     }
        // }
    }
    
    // print_SDL_close();

    destroy_board(&brd);



    return 0;
}
