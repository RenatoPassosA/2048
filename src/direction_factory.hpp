#ifndef DIRECTION_FACTORY_HPP
#define DIRECTION_FACTORY_HPP

#include "interface_move.hpp"
#include "left.hpp"
#include "right.hpp"
#include "up.hpp"
#include "down.hpp"


class DirectionFactory
{
	public:
		static interface_move_strategy *get_move(Direction dir);

};


#endif
