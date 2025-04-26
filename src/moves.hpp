#ifndef MOVES_HPP
#define MOVES_HPP

#include "board.hpp"

void move(Board& board, Direction dir);


//para fins de teste:
void move_left(Board &board);
void move_right(Board &board);
void move_down(Board &board);
void move_up(Board &board);

#endif