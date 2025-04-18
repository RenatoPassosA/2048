#include "board.hpp"

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

Board::Board()
{
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

Tile Board::grid_at(int x, int y) const
{
	return grid[x][y];
}

/*void	move_left()
{

}*/

















void Board::print_table()
{
	int x;
	int y;

	x = 0;
	y = 0;

	while (x < 4)
	{
		while (y < 4)
		{
			if (grid[x][y].get_value() != 0)
				std::cout << ' ' << grid[x][y].get_value();
			else
				std::cout << ' ' << grid[x][y].get_value();
			y++;
		}
		y = 0;
		x++;
		std::cout << std::endl;
	}
}
