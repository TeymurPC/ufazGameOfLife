#include <stdio.h>
#include <unistd.h>
#include "game.h"
#include "print_to_console.h"

int main(int argc, char const *argv[])
{
    struct board brd;
    for (int i = 0; i < 50; i++)
    {
            
        new_random_board(&brd);

        print_board(brd);
        sleep(1);
    }
    
    
    return 0;
}
