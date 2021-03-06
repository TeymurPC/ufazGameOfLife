#include "print_to_sdl.h"

    // The window we'll be rendering to
    SDL_Window* window = NULL;
    
    //The surface contained by the window
    SDL_Surface* screenSurface = NULL;

int print_SDL_init(int brd_width, int brd_height){
    int res = 0;
    const int SCREEN_WIDTH = brd_width*10;
    const int SCREEN_HEIGHT = brd_height*10;
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_EVENTS ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        res = 1;
    }else{
        window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL ){
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            res = 1;
        }else{
            screenSurface = SDL_GetWindowSurface( window );
        }
    }

    return res;
}

int print_SDL_print(struct board brd){
    
    SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0x00, 0x00, 0x00 ) );
    for (int i = 0; i < brd.height; i++)
    {
        for (int j = 0; j < brd.width; j++)
        {
            // printf((brd.cells[i][j] == ALIVE_CELL ? "\033[07m  \e[0m" : "  "));
            if (brd.cells[i][j] == ALIVE_CELL){
                const SDL_Rect rect = {j*10, i*10, 10, 10};

                SDL_FillRect(screenSurface, &rect, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ));
            }
        }
        printf("\n");
        
    }
    SDL_UpdateWindowSurface( window );
}

void print_SDL_close(){
    SDL_FreeSurface(screenSurface);
    screenSurface = NULL;

    SDL_DestroyWindow(window);
    window = NULL;

    SDL_Quit();
}