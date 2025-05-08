#ifndef DOWN_HPP
#define DOWN_HPP

#include "./board.hpp"
#include "interface_move.hpp"

class Down : public interface_move_strategy
{
	public:
	   	void	move(Board& board) override;
		bool	can_move(Board& board) override;
		
	private:	
		void	move_in_column_down(Board &board, int y);
		void	merge_in_column_down(Board &board, int y);
};

#endif
