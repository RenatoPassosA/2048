#include "up.hpp"

void	Up::move(Board &board)
{
	int y = 0;

	while (y < 4)
	{
		move_in_column_up(board, y);
		merge_in_column_up(board, y);
		move_in_column_up(board, y);
		y++;
	}
}

bool	Up::can_move(Board &board)
{
	int	x = 0;
	int	y = 0;
	
	while (x < 4)
	{
		while (y < 4)
		{
			if (board.grid_at(x,y).get_value() != 0 && check_up(board, x, y))
				return(true);
			y++;
		}
		y = 0;
		x++;
	}
	return(false);
}

void	Up::move_in_column_up(Board &board, int y)
{
	int x = 1;
	int value = 0;
	int target_value = 0;
	int target_row = 0;

	while (x < 4)
	{
		target_value = board.grid_at(target_row, y).get_value();
		value = board.grid_at(x, y).get_value();
		if (value && target_value == 0)
		{
			board.grid_at(target_row, y).set_value(value);
			board.grid_at(x, y).set_value(0);
			target_row++;
		}
		if (target_value != 0)
			target_row++;
		x++;
	}
}

void	Up::merge_in_column_up(Board &board, int y)
{
	int x = 1;
	int value = 0;
	int target_value = 0;
	int target_row = 0;

	while (x < 4)
	{
		target_value = board.grid_at(target_row, y).get_value();
		value = board.grid_at(x, y).get_value();
		if (value != 0 && value == target_value)
		{
			board.grid_at(target_row, y).set_value(value * 2);
			board.grid_at(x, y).set_value(0);
			board.update_score(value * 2);
		}
		target_row++;
		x++;
	}
}