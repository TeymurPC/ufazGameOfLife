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
 * @file print_to_console.h
 * @author Aghateymur Hasanzada and Gulzar Safarli
 * @brief This project is implementation og a famous cell automata project - Game of Life.
 * 
 * This file defines the way to print a Game of Life board to standart output.
 * @version 1.0.0
 * @date 2020-05-04
 */

#ifndef PRINT_TO_CONSOLE_H
#define PRINT_TO_CONSOLE_H

    #include <stdio.h>
    #include "../game/game.h"

    /**
     * @brief These definitions are used to indicate if printing is printing debug info or not
     */
    #define DEBUG_TRUE 1
    #define DEBUG_FALSE 0

    /**
     * @brief This function prints board structure to standart output
     * 
     * This function prints board to standart output. DEBUG_FALSE definition 
     * can be given as second argument to print each cell's neigbour on it.
     * @param brd a board structure to be printed
     * @param debug print debug info or not
     */
    void print_board(struct board brd, unsigned short debug);
#endif