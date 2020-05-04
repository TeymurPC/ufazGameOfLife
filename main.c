#include <unistd.h>
#include <SDL2/SDL.h>
#include <signal.h>
#include <getopt.h>
#include "game.h"
#include "print_to_console.h"
#include "print_to_sdl.h"

int quit = 0;

void quit_signal(){
    quit = 1;
}
int main(int argc, char *argv[])
{

    int brd_height = 50;
    int brd_width = 50;
    enum { SDL_PRINT, CONSOLE_PRINT } print_mode = CONSOLE_PRINT;
    int board_type = CLIPPED_BOARD;
    int debug_mode = DEBUG_FALSE;
    int c;


    while ( (c = getopt(argc, argv, "scdw:h:")) != -1){
        switch (c)
        {
            case 'w':
            {
                brd_width = atoi(optarg);
                break;
            }
            case 'h':
                brd_height = atoi(optarg);
                break;
            case 's':
                print_mode = SDL_PRINT;
                break;
            case 'c':
                board_type = CIRCULAR_BOARD;
                break;
            case 'd':
                debug_mode = DEBUG_TRUE;
                break;
            case '?':
                if (optopt == 'w' || optopt == 'h')
                fprintf (stderr, "Option -%c requires an argument.\n", optopt);
                else if (isprint (optopt))
                fprintf (stderr, "Unknown option `-%c'.\n", optopt);
                else
                fprintf (stderr,
                        "Unknown option character `\\x%x'.\n",
                        optopt);
                exit(EXIT_FAILURE);
                break;
            default:
                printf("Usage:\n%s [-w width] [-h height] [options]\nOptions:\n\t-s\t\tPrint to SDL instead of standart output\n\t-c\t\tMake board type Circular instead of Clipped\n\t-d\t\tDebug mode on for standart input\n", argv[0]);
                exit(EXIT_FAILURE);
                break;
        }
    }
    

    struct board brd;
    init_board(&brd, brd_width, brd_height, board_type);
    new_random_board(&brd);

    SDL_Event e;
    if(print_mode == SDL_PRINT){
        print_SDL_init();
        print_SDL_print(brd);
    }else{
        print_board(brd, debug_mode);
    }

    signal(SIGINT, quit_signal);

    while(!quit){
        sleep(1);
        brd = next_board(brd);

        if(print_mode == SDL_PRINT){
            print_SDL_print(brd);
            print_SDL_print(brd);
            while (SDL_PollEvent(&e)){
                if (e.type == SDL_QUIT){
                    quit = 1;
                }
            }
        }else{
            print_board(brd, debug_mode);
        }
    }
    
    if(print_mode == SDL_PRINT){
        print_SDL_close();
    }

    destroy_board(&brd);



    return 0;
}
