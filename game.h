#define BOARD_HEIGHT 50
#define BOARD_WIDTH 50
#define DEAD_CELL 0
#define ALIVE_CELL 1

struct cell{
    int x;
    int y;
    unsigned int dead;
};
struct board{
    struct cell cells[BOARD_WIDTH][BOARD_HEIGHT];
};


void new_random_board(struct board *brd);

void print_board(struct board);