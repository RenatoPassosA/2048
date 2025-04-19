#include "moves.hpp"
#include "board.hpp"


/*
checar o limite das bordas
checar se tem tile no caminho
	se tiver ver se tem o mesmo valor
		se tiver mergear
		se n tiver servir como barreira
gerar um tile aleatório novo
*/

/*
x: altura
y: largura
*/


static void	move_left(Board &board)
{
	int x = 0;
	int y = 1;
	int value;
	int target_col = 0;

	while (x < 4)
	{
		while (y < 4)
		{
			value = board.grid_at(x, y).get_value();
			if (value)
			{
				if (board.grid_at(x, target_col).get_value() == 0)
				{
					board.grid_at(x, target_col).set_value(value);
					board.grid_at(x, y).set_value(0);
				}
				else if (value == board.grid_at(x, target_col).get_value())
				{
					board.grid_at(x, target_col).set_value(value * 2);
					board.grid_at(x, y).set_value(0);
					target_col++;
				}
			}
			y++;
		}
		y = 1;
		x++;
	}
}

static void	move_right(Board &board)
{
	int x = 0;
	int y = 2;
	int value;
	int target_col = 3;

	while (x < 4)
	{
		while (y >= 0)
		{
			value = board.grid_at(x, y).get_value();
			if (value)
			{
				if (board.grid_at(x, target_col).get_value() == 0)
				{
					board.grid_at(x, target_col).set_value(value);
					board.grid_at(x, y).set_value(0);
				}
				else if (value == board.grid_at(x, target_col).get_value())
				{
					board.grid_at(x, target_col).set_value(value * 2);
					board.grid_at(x, y).set_value(0);
					target_col--;
				}
			}
			y--;
		}
		y = 2;
		x++;
	}
}

static void	move_up(Board &board)
{
	int x = 1;
	int y = 0;
	int value;
	int target_row = 0;

	while (x < 4)
	{
		while (y < 4)
		{
			value = board.grid_at(x, y).get_value();
			if (value)
			{
				if (board.grid_at(target_row, y).get_value() == 0)
				{
					board.grid_at(target_row, y).set_value(value);
					board.grid_at(x, y).set_value(0);
				}
				else if (value == board.grid_at(target_row, y).get_value())
				{
					board.grid_at(target_row, y).set_value(value * 2);
					board.grid_at(x, y).set_value(0);
					target_row++;
				}
			}
			y++;
		}
		target_row = 0;
		y = 0;
		x++;
	}
}
static void	move_down(Board &board)
{
	int x = 2;
	int y = 0;
	int value;
	int target_row = 3;

	while (x >= 0)
	{
		while (y < 4)
		{
			value = board.grid_at(x, y).get_value();
			if (value)
			{
				if (board.grid_at(target_row, y).get_value() == 0)
				{
					board.grid_at(target_row, y).set_value(value);
					board.grid_at(x, y).set_value(0);
				}
				else if (value == board.grid_at(target_row, y).get_value())
				{
					board.grid_at(target_row, y).set_value(value * 2);
					board.grid_at(x, y).set_value(0);
					target_row--;
				}
			}
			y++;
		}
		target_row = 3;
		y = 0;
		x--;
	}
}

void move(Board &board, Direction dir)
{
	if (dir == Direction::left)
		move_left(board);
	else if (dir == Direction::right)
		move_right(board);
	else if (dir == Direction::down)
		move_down(board);
	else if (dir == Direction::up)
		move_up(board);
}


/* 
na vdd tá bugando quando são numeros diferentes (2 e 4)
fazer testes.
erro mover para direita:
 0 0 0 0
 4 2 0 0
 0 0 0 0
 0 0 0 0*/