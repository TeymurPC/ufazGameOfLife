/********************************************************************************************
 * Copyright (C) 2020 by Hasanzada Aghateymur and Gulzar Safarli                            *
 *                                                                                          *
 * This file is part of UFAZ Game Of Life Project.                                          *
 *  UFAZ Game Of Life Project is free software: you can redistribute it and/or modify it    *
 *  under the terms of the GNU Lesser General Public License as published                   *
 *  by the Free Software Foundation, either version 3 of the License, or                    *
 *  (at your option) any later version.                                                     *
 *                                                                                          *
 *  UFAZ Game Of Life Project is distributed in the hope that it will be useful             *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of                          *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                                    *
 ******************************************************************************************/

/**
 * @file main.c
 * @brief This project is implementation of a famous cell automata project - Game of Life.
 * @author Aghateymur Hasanzada and Gulzar Safarli
 * 
 * @version 1.0.0
 * @date 2020-05-04
 */

/*! \mainpage UFAZ Game Of Life
 *
 * This project is an implementation of a famous cell automata project - Game Of Life
 * 
 * Contents: 
 * - \subpage howToInstall "How to install this project"
 * - \subpage howToRun "How to run this project"
 */

/*! \page howToInstall How to install
 * First clone the project with:
 * \code
 * git clone https://github.com/ufazGameOfLife/ufazGameOfLife.git
 * \endcode
 * Make sure you have make, cmake, sdl and cunit installed then:
 * \code
 * cd ufazGameOfLife
 * cmake .
 * make
 * \endcode
 */

/*! \page howToRun How to run
 * Usage:\n
 * ./ufazGameOfLife [-w width] [-h height] [options]\n
 * Options:\n
 * &emsp;-s&emsp;&emsp;Print to SDL instead of standart output\n
 * &emsp;-c&emsp;&emsp;Make board type Circular instead of Clipped\n
 * &emsp;-d&emsp;&emsp;Debug mode on for standart input\n
 */


#include <unistd.h>
#include <SDL2/SDL.h>
#include <signal.h>
#include <getopt.h>
#include "game/game.h"
#include "console/print_to_console.h"
#include "sdl2_print/print_to_sdl.h"

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
        print_SDL_init(brd_width, brd_height);
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
