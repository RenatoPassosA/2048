#include "../game.hpp"
#include "../tests/tests.hpp"

int	main(void)
{
	Board board;
	

	int initial[4][4] = {
		{4, 0, 0, 2},
		{4, 2, 0, 2},
		{2, 2, 2, 4},
		{0, 2, 2, 4}
	};
/*
	{0, 2, 4, 4},     
	{0, 0, 4, 4},
	{4, 4, 2, 2},
	{2, 2, 2, 2}     2  2  0         
*/
	load_board(board, initial);
	set_new_tile_after_movement(board);
	set_new_tile_after_movement(board);
	board.print_table();
	return (0);
}
