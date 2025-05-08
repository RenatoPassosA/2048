#ifndef UP_HPP
#define UP_HPP

#include "./board.hpp"
#include "interface_move.hpp"

class Up : public interface_move_strategy
{
	public:
	   	void	move(Board& board) override;
		bool	can_move(Board& board) override;
		
	private:
		void	move_in_column_up(Board &board, int y);
		void	merge_in_column_up(Board &board, int y);
};

#endif
