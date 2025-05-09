/*
classe board:
responsável por gerenciar a parte lógica do jogo.
guarda todos os tiles do tabuleiro numa matriz
lida com a criação de tiles, movimentação do board, placar, histórico, desfazer e new game.
*/

#include "board.hpp"
#include "direction_factory.hpp"

Board::Board()
{
	std::srand(static_cast<unsigned>(time(nullptr)));
	score = 0;
	undo_count = 5;

	int x = 0;
	int y = 0;
	
	while (x < 4)
	{
		while (y < 4)
		{
			grid[x][y] = Tile(x, y);
			y++;			
		}
		y = 0;
		x++;
	}
	set_initial_tiles();
}

Tile &Board::grid_at(int x, int y)
{
	return grid[x][y];
}

Tile Board::set_random_tile()
{
	int	rand_x;
	int	rand_y;
	int	rand_val;
	
	rand_x = rand() % 4;
	rand_y = rand() % 4;
	rand_val = rand() % 10;

	if (rand_val >= 8)
		rand_val = 4;
	else
		rand_val = 2;

	Tile random_tile(rand_x, rand_y);
	random_tile.set_value(rand_val);
	
	return (random_tile);
}

void Board::set_initial_tiles()
{
	Tile	a = set_random_tile();
	Tile	b = set_random_tile();
	
	while ((a.get_x() == b.get_x()) && (a.get_y() == b.get_y()))
		a = set_random_tile();

	grid[a.get_x()][a.get_y()].set_value(a.get_value());
	grid[b.get_x()][b.get_y()].set_value(b.get_value());
}

bool	has_empty_tile(Board &board)
{
	int x = 0;
	int y = 0;

	while (x < 4)
	{
		while (y < 4)
		{
			if (board.grid_at(x, y).get_value() == 0)
				return true;
			y++;
		}
		y = 0;
		x++;
	}
	return false;
}

void	Board::set_new_tile_after_movement()
{
	if (!has_empty_tile(*this))
		return ;

	Tile new_tile = this->set_random_tile();
	int x = new_tile.get_x();
	int y = new_tile.get_y();

	while (this->grid_at(x, y).get_value() != 0)
	{
		new_tile = this->set_random_tile();
		x = new_tile.get_x();
		y = new_tile.get_y();
	}
	this->grid_at(x, y).set_value(new_tile.get_value());
}

void Board::handle_direction(Direction dir)
{
	interface_move_strategy* find_direction = DirectionFactory::get_move(dir);
	if (!find_direction->can_move(*this))
	{
		delete find_direction;
		return ;
	}
	save_history();
    find_direction->move(*this);
    delete find_direction;
	set_new_tile_after_movement();
}

bool check_up(Board &board, int x, int y)
{
	int up = x - 1;
	if (up < 0)
		return (false);
	
	int up_value = board.grid_at(up, y).get_value();
	int current_value = board.grid_at(x, y).get_value();
	
	return (up_value == 0 || up_value == current_value);
}

bool check_down(Board &board, int x, int y)
{
	int down = x + 1;
	if (down > 3)
		return (false);

	int down_value = board.grid_at(down, y).get_value();
	int current_value = board.grid_at(x, y).get_value();

	return (down_value == 0 || down_value == current_value);
}

bool check_left(Board &board, int x, int y)
{
	int left = y - 1;
	if (left < 0)
		return (false);

	int left_value = board.grid_at(x, left).get_value();
	int current_value = board.grid_at(x, y).get_value();
	
	return (left_value == 0 || left_value == current_value);
}

bool check_right(Board &board, int x, int y)
{
	int right = y + 1;
	if (right > 3)
		return (false);

	int right_value = board.grid_at(x, right).get_value();
	int current_value = board.grid_at(x, y).get_value();
	
	return (right_value == 0 || right_value == current_value);
}

static bool check_neighbors(Board &board, int x, int y)
{
	return (check_up(board, x, y) ||
	check_down(board, x, y) ||
	check_left(board, x, y) ||
	check_right(board, x, y));
}

bool	Board::check_end_game()
{
	int		x = 0;
	int		y = 0;
	int		value_flag = 0;
	bool	merge_flag;

	while (x < 4)
	{
		while (y < 4)
		{
			value_flag = this->grid_at(x, y).get_value();
			if (value_flag == 0)
				return (true); //pode mover
			merge_flag = check_neighbors(*this, x, y);
			if (merge_flag)
				return (true); //pode mover
			y++;
		}
		y = 0;
		x++;
	}
	return (false);
}

int Board::get_score()
{
	return (this->score);
}

void	Board::set_score(int previous_score)
{
	this->score = previous_score;
};

void Board::update_score(int val)
{
	this->score += val;
}

bool	Board::undo()
{
	int x = 0;
	int y = 0;

	if (this->undo_count == 0 || history.empty())
		return false;
	this->decrement_undo();
	BoardState previous = history.front();
	history.erase(history.begin());
	while (x < 4)
	{
		while (y < 4)
		{
			this->grid_at(x, y).set_value(previous.grid[x][y]);
			y++;
		}
		y = 0;
		x++;
	}
	this->set_score(previous.score);
	return (true);
}

int Board::get_undo_counter()
{
	return (this->undo_count);
}

void Board::decrement_undo()
{
	this->undo_count--;
}

void		Board::reset_undo_counter()
{
	this->undo_count = 0;
};

void	Board::save_history()
{
	BoardState state;
	int 		x = 0;
	int 		y = 0;

	while (x < 4)
	{
		while (y < 4)
		{
			state.grid[x][y] = grid_at(x, y).get_value();
			y++;
		}
		y = 0;
		x++;
	}
	state.score = this->score;

	history.insert(history.begin(), state);
	if (history.size() > 5)
		history.pop_back();
}

void	Board::delete_history()
{
	history.clear();
}

bool Board::has_history() const
{
    return !history.empty();
}

void	Board::new_game()
{
	int x = 0;
	int y = 0;

	while (x < 4)
	{
		while (y < 4)
		{
			grid_at(x, y).set_value(0);
			y++;
		}
		y = 0;
		x++;
	}
	set_initial_tiles();
	this->score = 0;
	this->undo_count = 5;	
}
