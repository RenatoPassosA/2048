#include "../game.hpp"

int	main(void)
{
	Direction dir_l = Direction::left;
	Direction dir_r = Direction::right;
	Direction dir_u = Direction::up;
	Direction dir_d = Direction::down;

	srand(time(NULL));
	Board board;
	board.print_table();
	board.handle_direction(dir_l);
	std::cout << "            " << std::endl;
	board.print_table();
	board.handle_direction(dir_r);
	std::cout << "            " << std::endl;
	board.print_table();
	board.handle_direction(dir_u);
	std::cout << "            " << std::endl;
	board.print_table();
	board.handle_direction(dir_d);
	std::cout << "            " << std::endl;
	board.print_table();

	return (0);
}
