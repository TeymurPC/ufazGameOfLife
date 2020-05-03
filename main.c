#include <unistd.h>
#include "game/game.h"
#include "console/print_to_console.h"

int main(int argc, char const *argv[])
{
    struct board brd;
    new_random_board(&brd);
    print_board(brd);

    while(1){
        sleep(1);
        brd = new_board(brd);
        print_board(brd);
    }

    return 0;
}
