#ifndef RIGHT_HPP
#define RIGHT_HPP

#include "./board.hpp"
#include "interface_move.hpp"

class Right : public interface_move_strategy
{
	public:
	   	void	move(Board& board) override;
		bool	can_move(Board& board) override;
		
	private:
		void	move_in_row_right(Board &board, int x);
		void	merge_in_row_right(Board &board, int x);
};

#endif
