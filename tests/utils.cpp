#include "tests.hpp"

void	load_board(Board &board, int value[4][4])
{
	int x = 0;
	int y = 0;

	while (x < 4)
	{
		while (y < 4)
		{
			board.grid_at(x, y).set_value(value[x][y]);
			y++;
		}
		y = 0;
		x++;
	}
}

bool	compare_board(Board &board, int expected[4][4])
{
	int x = 0;
	int y = 0;

	while (x < 4)
	{
		while (y < 4)
		{
			if (board.grid_at(x, y).get_value() != expected[x][y])
				return false;
			y++;
		}
		y = 0;
		x++;
	}
	return true;
}

void print_table(Board &board)
{
	int x;
	int y;

	x = 0;
	y = 0;

	while (x < 4)
	{
		while (y < 4)
		{
			if (board.grid_at(x, y).get_value() != 0)
				std::cout << ' ' << board.grid_at(x, y).get_value();
			else
				std::cout << ' ' << board.grid_at(x, y).get_value();
			y++;
		}
		y = 0;
		x++;
		std::cout << std::endl;
	}
}

void	check_print(bool result, Board board, int expected[4][4])
{
	if (!result)
	{
		Board expected_board;
		load_board(expected_board, expected);
		std::cout << "EXPECTED: \n" <<std::endl; 
		print_table(expected_board);

		std::cout << "After func: \n" <<std::endl;
		print_table(board);
	}
}