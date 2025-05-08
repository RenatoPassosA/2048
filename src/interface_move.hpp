#ifndef MOVE_HPP
#define MOVE_HPP

#include "./board.hpp"

class interface_move_strategy
{
	public:
		virtual void move(Board&) = 0;
		virtual bool can_move(Board& board) = 0;
		virtual ~interface_move_strategy() = default;
};

#endif
