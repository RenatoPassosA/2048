#include "moves.hpp"
#include "board.hpp"
#include "tile.hpp"

static void	move_in_row_left(Board &board, int x)
{
	int y = 1;
	int value = 0;
	int target_value = 0;
	int target_col = 0;

	while (y < 4)
	{
		target_value = board.grid_at(x, target_col).get_value();
		value = board.grid_at(x, y).get_value();
		if (value && target_value == 0)
		{
			board.grid_at(x, target_col).set_value(value);
			board.grid_at(x, y).set_value(0);
			target_col++;
		}
		if (target_value != 0)
			target_col++;
		y++;
	}
}

static void	merge_in_row_left(Board &board, int x)
{
	int y = 1;
	int value = 0;
	int target_value = 0;
	int target_col = 0;

	while (y < 4)
	{
		target_value = board.grid_at(x, target_col).get_value();
		value = board.grid_at(x, y).get_value();
		if (value != 0 && value == target_value)
		{
			board.grid_at(x, target_col).set_value(value * 2);
			board.grid_at(x, y).set_value(0);
			board.update_score(value * 2);
		}
		target_col++;
		y++;
	}
}

static void	move_in_row_right(Board &board, int x)
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

static void	merge_in_row_right(Board &board, int x)
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

void	move_in_column_down(Board &board, int y)
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

static void	merge_in_column_down(Board &board, int y)
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

void	move_in_column_up(Board &board, int y)
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

static void	merge_in_column_up(Board &board, int y)
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

void	move_left(Board &board)
{
	int	x = 0;
	while (x < 4)
	{
		move_in_row_left(board, x);
		merge_in_row_left(board, x);
		move_in_row_left(board, x);
		x++;
	}
}


void	move_right(Board &board)
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

void	move_down(Board &board)
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
void	move_up(Board &board)
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

void	move(Board &board, Direction dir)
{
	board.save_history();
	if (dir == Direction::left)
		move_left(board);
	else if (dir == Direction::right)
		move_right(board);
	else if (dir == Direction::down)
		move_down(board);
	else if (dir == Direction::up)
		move_up(board);
	board.set_new_tile_after_movement();
} 