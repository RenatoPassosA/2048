#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <random>
#include "tile.hpp"

enum class Direction {
    left,
    right,
    up,
    down
};

class Board{
	private:
		Tile	grid[4][4];
		int		score;
	
	public:
		Board();
		Tile	set_random_tile();
		void	set_initial_tiles();
		void	handle_direction(Direction dir);
		/*
		void	move_right();
		void	move_down();
		void	move_up();
		
		void	check_end_game();*/
		Tile	&grid_at(int x, int y);
		void	print_table();
};

#endif