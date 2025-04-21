#include "../game.hpp"
#include "../tests/tests.hpp"

int	main(void)
{
	Board board;

	int initial[4][4] = {
		{4, 4, 32, 32},
		{128, 128, 0, 2},
		{64, 64, 16, 16},
		{2, 256, 256, 2}
	};

	load_board(board, initial);
	move_left(board);
	board.print_table();
	
	
	return (0);
}
