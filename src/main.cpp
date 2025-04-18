#include <iostream>
#include "tile.hpp"
#include "board.hpp"

int	main(void)
{
	srand(time(NULL));
	Board board;
	board.print_table();
	
	return (0);
}
