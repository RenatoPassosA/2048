#ifndef TESTS_HPP
# define TESTS_HPP

#include "../src/board.hpp"
#include "../src/tile.hpp"


void	load_board(Board &board, int value[4][4]);
bool	compare_board(Board &board, int expected[4][4]);
void	check_print(bool result, Board board, int expected[4][4]);


#endif