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
 * @file print_to_sdl.h
 * @author Aghateymur Hasanzada and Gulzar Safarli
 * @brief This project is implementation og a famous cell automata project - Game of Life.
 * 
 * This file defines the way to show board on GUI (Graphic User Interface).
 * @version 1.0.0
 * @date 2020-05-04
 */

#ifndef PRINT_TO_SDL_H
#define PRINT_TO_SDL_H

    #include "game.h"
    #include "SDL2/SDL.h"


    /**
     * @brief Initialize GUI
     * 
     * @param brd_width Board Width
     * @param brd_height Board Height
     * @return int 0 if succesfully initialized GUI, 1 if had problem while initializing GUI
     */
    int print_SDL_init(int brd_width, int brd_height);

    /**
     * @brief Show current board on GUI
     * 
     * @param brd board structure to be shown
     * @return int int 0 if succesfully showed board on GUI, 1 if had problem while showing board on GUI
     */
    int print_SDL_print(struct board brd);

    /**
     * @brief Quit GUI
     * 
     */
    void print_SDL_close();

#endif