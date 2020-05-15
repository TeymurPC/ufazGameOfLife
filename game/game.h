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
 * @file game.h
 * @brief This project is implementation og a famous cell automata project - Game of Life.
 * @author Aghateymur Hasanzada and Gulzar Safarli
 * 
 * This file defines basic game mechanics needed to run the project.
 * @version 1.0.0
 * @date 2020-05-04
 */


#ifndef GAME_H
#define GAME_H

    #include <stdlib.h>
    #include <stdio.h>
    #include <time.h>
    

    /**
     * @brief Definitions of DEAD and ALIVE Cells
     * 
     * The board consists of either dead and alive cells. So it's better to define them so
     * you don't have to deal with only 1 and 0s afterwards
     */
    #define DEAD_CELL 0
    #define ALIVE_CELL 1

    /**
     * @brief Definitions of Clipped and Circular board types
     * 
     * The next board is created with the specific rules considering each cell's current
     * neighbours count. And counting neighbours can be done with two ways - Clipped or Circular.
     * This are the definitions that board structure takes for counting neighbours. 
     */
    #define CIRCULAR_BOARD 1
    #define CLIPPED_BOARD 0

    /**
     * @brief The board stucture which holds all cells and the board's info.
     * 
     * All game related mechanics/functions work on this structure which defines
     * the datas that board holds.
     */
    struct board{
        unsigned short **cells; /**< board#cells is 2D array which holds all cells in it as 2D. */
        unsigned short circular_flag; /**< board#circular_flag holds info about if the cells' neigbours are counted as circular or clipped */
        int height; /**< board#height holds the height of the board */
        int width; /**< board#width holds the width of the board */
    };

    /**
     * @brief It randomly assigns DEAD_CELL or ALIVE_CELL on the existing brd board's cells.
     * 
     * @param brd an already initialized board structure to be filled randomly
     */
    void new_random_board(struct board *brd);

    /**
     * @brief Calculates a cell's neigbours with Clipped technique.
     * 
     * This functions calculates the count of neigbours of a given cell using clipped technique
     * 
     * 
     * Example board:
     * @code
     *    0 1 2 3 4 5
     *    -----------
     * 0| 1 0 0 1 0 0
     * 1| 1 1 0 1 1 0
     * 2| 0 1 0 0 1 1
     * 3| 1 0 0 0 1 1
     * 4| 0 0 0 0 1 0
     * 5| 1 1 1 0 0 1
     * @endcode
     * 
     * Neighbours of (x: 3, y: 1) cell is 3\n 
     * Neighbours of (x: 5, y: 3) cell is 4\n 
     * Neighbours of (x: 2, y: 5) cell is 1\n 
     * 
     * @param brd the board structure to calculate from
     * @param x the x coordinate of the cell
     * @param y the y coordinate of the cell
     * @return int count off the neighbours using clipped techique
     */
    int neighbours_clipped(struct board brd, int x, int y);

    /**
     * @brief Calculates a cell's neigbours with Circular technique.
     * 
     * This functions calculates the count of neigbours of a given cell using circular technique
     * 
     * Example board:
     * @code
     *    0 1 2 3 4 5
     *    -----------
     * 0| 1 0 0 1 0 0
     * 1| 1 1 0 1 1 0
     * 2| 0 1 0 0 1 1
     * 3| 1 0 0 0 1 1
     * 4| 0 0 0 0 1 0
     * 5| 1 1 1 0 0 1
     * @endcode
     * 
     * Neighbours of (x: 3, y: 1) cell is 3\n 
     * Neighbours of (x: 5, y: 3) cell is 5\n 
     * Neighbours of (x: 2, y: 5) cell is 2\n 
     * 
     * @param brd the board structure to calculate from
     * @param x the x coordinate of the cell
     * @param y the y coordinate of the cell
     * @return int count off the neighbours using circular techique
     */
    int neighbours_circular(struct board brd, int x, int y);

    /**
     * @brief Creates a new board from board using specified rules
     * 
     * Rules:
     * 1. If an alive cell has exactly 2 or 3 neighbours, it stays alive. Otherwise, it dies
     * 2. If a dead cells has exactly 3 neighbours, it becomes and alive cell. Otherwise,, it stays dead
     * 
     * Neigbours are calculated based on brd#circular_flag
     * @param brd 
     * @return struct board 
     */
    struct board next_board(struct board brd);

    /**
     * @brief Initializes board
     * 
     * After creating new board, you need to allocate brd#cells 2D array for it and also set other parameters. This function does it.
     * @param brd an already created board structure to be initialized
     * @param width board's width
     * @param height board's height
     * @param circular_flag tells if the brd#cells' neighbours are calculated as circluar or clipped.
     */
    void init_board(struct board *brd, int width, int height, unsigned short circular_flag);

    /**
     * @brief Free memory that has been allocated for the board structure
     * 
     * @param brd the board to be destroyed
     */
    void destroy_board(struct board *brd);


    
    
#endif

