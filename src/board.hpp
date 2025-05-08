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
		Tile	&grid_at(int x, int y);
		Tile	set_random_tile();
		void	set_initial_tiles();
		void	set_new_tile_after_movement();

		void	handle_direction(Direction dir);

		bool	check_end_game();

		int		get_score();
		void	update_score(int val);
		
		bool	undo();
		int		get_undo_counter();
		void	decrement_undo();
		void	reset_undo_counter();

		void	new_game();

		void	save_history();
		void	delete_history();
		bool 	has_history() const;

		

		
		
		void	print_table();
};

bool check_right(Board &board, int x, int y);
bool check_left(Board &board, int x, int y);
bool check_down(Board &board, int x, int y);
bool check_up(Board &board, int x, int y);

#endif