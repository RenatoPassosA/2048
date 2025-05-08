#include "direction_factory.hpp"
#include "interface_move.hpp"

interface_move_strategy* DirectionFactory::get_move(Direction dir)
{
	if (dir == Direction::left)
		return new Left();
	else if (dir == Direction::right)
		return new Right();
	else if (dir == Direction::down)
		return new Down();
	else if (dir == Direction::up)
		return new Up();
	return nullptr;
}

