#include <gtest/gtest.h>
#include "../src/board.hpp"
#include "../src/tile.hpp"

TEST(set_random_tile, create_new_tile)
{
    
	Tile a;
	Board b;

	a = b.set_random_tile();

	EXPECT_TRUE(a.get_value() == 2 || a.get_value() == 4);
	EXPECT_TRUE(a.get_x() >= 0 && a.get_x() <= 3);
	EXPECT_TRUE(a.get_y() >= 0 && a.get_y() <= 3);
}

TEST(set_initial_tiles, setting_two_tiles_on_game_init)
{
	// O construtor de Board já chama set_initial_tiles() automaticamente.
	Board	board;
	Tile	a;
	Tile	b;

	int	x = 0;
	int	y = 0;
	int counter = 0;

	while(x < 4)
	{
		while (y < 4)
		{
			if (board.grid_at(x, y).get_value() != 0)
			{
				counter++;
				if (counter == 1)
				{
					a.set_value(board.grid_at(x, y).get_value());
					a.set_x(x);
					a.set_y(y);
				}
				else if (counter == 2)
				{
					b.set_value(board.grid_at(x, y).get_value());
					b.set_x(x);
					b.set_y(y);
				}
			}
			y++;
		}
		y = 0;
		x++;
	}

	EXPECT_TRUE(counter == 2) << "Quantidade de tiles encontrada: " << counter;
	EXPECT_FALSE(a.get_x() == b.get_x() && a.get_x() == b.get_x())
	 << "Coordenadas (x, y) dos dois tiles são iguais: " << a.get_x() << ", " << a.get_y() << " e " << b.get_x() << ", " << b.get_y();

}




