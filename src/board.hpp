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
		Tile				grid[4][4];
		int					score;
		std::vector<Board>	history;
		int					undo_count;
	
	public:
		Board();
		Tile	set_random_tile();
		void	set_initial_tiles();
		void	set_new_tile_after_movement();
		void	handle_direction(Direction dir);
		bool	can_move();
		void	update_score(int val);
		int		get_score();
		void	save_history();
		bool	undo();
		void	decrement_undo();


		
		//void	check_end_game();
		Tile	&grid_at(int x, int y);
		void	print_table();
};

#endif