/*
faz a lógica da movimentação em coluna para fazer com que os tiles encaixem nos espaços vazios
faz a lógica para mergear tiles com o mesmo valor
*/
#include "down.hpp"

void	Down::move(Board &board)
{
	int y = 0;

	while (y < 4)
	{
		move_in_column_down(board, y);
		merge_in_column_down(board, y);
		move_in_column_down(board, y);
		y++;
	}
}

bool	Down::can_move(Board &board)
{
	int	x = 0;
	int	y = 0;
	
	while (x < 4)
	{
		while (y < 4)
		{
			if (board.grid_at(x,y).get_value() != 0 && check_down(board, x, y))
				return(true);
			y++;
		}
		y = 0;
		x++;
	}
	return(false);
}

void	Down::move_in_column_down(Board &board, int y)
{
	int x = 2;
	int value = 0;
	int target_value = 0;
	int target_row = 3;

	while (x >= 0)
	{
		target_value = board.grid_at(target_row, y).get_value();
		value = board.grid_at(x, y).get_value();
		if (value && target_value == 0)
		{
			board.grid_at(target_row, y).set_value(value);
			board.grid_at(x, y).set_value(0);
			target_row--;
		}
		if (target_value != 0)
			target_row--;
		x--;
	}
}

void	Down::merge_in_column_down(Board &board, int y)
{
	int x = 2;
	int value = 0;
	int target_value = 0;
	int target_row = 3;

	while (x >= 0)
	{
		target_value = board.grid_at(target_row, y).get_value();
		value = board.grid_at(x, y).get_value();
		if (value != 0 && value == target_value)
		{
			board.grid_at(target_row, y).set_value(value * 2);
			board.grid_at(x, y).set_value(0);
			board.update_score(value * 2);
		}
		target_row--;
		x--;
	}
}