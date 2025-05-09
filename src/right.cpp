/*
faz a lógica da movimentação em coluna para fazer com que os tiles encaixem nos espaços vazios
faz a lógica para mergear tiles com o mesmo valor
*/
#include "right.hpp"

void	Right::move(Board &board)
{
	int	x = 0;
	while (x < 4)
	{
		move_in_row_right(board, x);
		merge_in_row_right(board, x);
		move_in_row_right(board, x);
		x++;
	}
}

bool	Right::can_move(Board &board)
{
	int	x = 0;
	int	y = 0;
	
	while (x < 4)
	{
		while (y < 4)
		{
			if (board.grid_at(x,y).get_value() != 0 && check_right(board, x, y))
				return(true);
			y++;
		}
		y = 0;
		x++;
	}
	return(false);
}

void	Right::move_in_row_right(Board &board, int x)
{
	int y = 2;
	int value = 0;
	int target_value = 0;
	int target_col = 3;

	while (y >= 0)
	{
		target_value = board.grid_at(x, target_col).get_value();
		value = board.grid_at(x, y).get_value();
		if (value && target_value == 0)
		{
			board.grid_at(x, target_col).set_value(value);
			board.grid_at(x, y).set_value(0);
			target_col--;
		}
		if (target_value != 0)
			target_col--;
		y--;
	}
}

void	Right::merge_in_row_right(Board &board, int x)
{
	int y = 2;
	int value = 0;
	int target_value = 0;
	int target_col = 3;

	while (y >= 0)
	{
		target_value = board.grid_at(x, target_col).get_value();
		value = board.grid_at(x, y).get_value();
		if (value != 0 && value == target_value)
		{
			board.grid_at(x, target_col).set_value(value * 2);
			board.grid_at(x, y).set_value(0);
			board.update_score(value * 2);
		}
		target_col--;
		y--;
	}
}