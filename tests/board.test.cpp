#include <gtest/gtest.h>
#include "../src/board.hpp"
#include "../src/tile.hpp"
#include "./tests.hpp"

//TESTS board initialization
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

//TESTS move left
TEST(move_left, simple_move_left)
{
	Board board;

	int initial[4][4] = {
		{2, 0, 0, 0},
		{0, 0, 2, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};
	int expected[4][4] = {
		{2, 0, 0, 0},
		{2, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};

	load_board(board, initial);
	move_left(board);
	bool result = compare_board(board, expected);

	check_print(result, board, expected);

	ASSERT_TRUE(result);
}

TEST(move_left, simple_move_left_no_merge)
{
	Board board;

	int initial[4][4] = {
		{0, 0, 2, 4},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};
	int expected[4][4] = {
		{2, 4, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};

	load_board(board, initial);
	move_left(board);
	bool result = compare_board(board, expected);

	check_print(result, board, expected);

	ASSERT_TRUE(result);

}

TEST(move_left, simple_move_left_with_merge)
{
	Board board;

	int initial[4][4] = {
		{2, 2, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};
	int expected[4][4] = {
		{4, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};

	load_board(board, initial);
	move_left(board);
	bool result = compare_board(board, expected);

	check_print(result, board, expected);

	ASSERT_TRUE(result);
}

TEST(move_left, complex_move_left)
{
	Board board;

	int initial[4][4] = {
		{2, 0, 0, 0},
		{0, 0, 2, 0},
		{0, 0, 0, 2},
		{0, 2, 0, 0}
	};
	int expected[4][4] = {
		{2, 0, 0, 0},
		{2, 0, 0, 0},
		{2, 0, 0, 0},
		{2, 0, 0, 0}
	};

	load_board(board, initial);
	move_left(board);
	bool result = compare_board(board, expected);

	check_print(result, board, expected);

	ASSERT_TRUE(result);
}

TEST(move_left, complex_move_left_no_merge)
{
	Board board;

	int initial[4][4] = {
		{2, 4, 0, 0},
		{0, 4, 2, 0},
		{0, 4, 0, 2},
		{0, 2, 0, 4}
	};
	int expected[4][4] = {
		{2, 4, 0, 0},
		{4, 2, 0, 0},
		{4, 2, 0, 0},
		{2, 4, 0, 0}
	};

	load_board(board, initial);
	move_left(board);
	bool result = compare_board(board, expected);

	check_print(result, board, expected);

	ASSERT_TRUE(result);
}

TEST(move_left, complex_move_left_with_merge)
{
	Board board;

	int initial[4][4] = {
		{4, 4, 0, 0},
		{0, 2, 2, 2},
		{0, 0, 2, 2},
		{2, 2, 2, 2}
	};
	int expected[4][4] = {
		{8, 0, 0, 0},
		{4, 2, 0, 0},
		{4, 0, 0, 0},
		{4, 4, 0, 0}
	};

	load_board(board, initial);
	move_left(board);
	bool result = compare_board(board, expected);

	check_print(result, board, expected);

	ASSERT_TRUE(result);
}

//TESTS move right
TEST(move_right, simple_move_right)
{
	Board board;

	int initial[4][4] = {
		{2, 0, 0, 0},
		{0, 0, 2, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};
	int expected[4][4] = {
		{0, 0, 0, 2},
		{0, 0, 0, 2},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};

	load_board(board, initial);
	move_right(board);
	bool result = compare_board(board, expected);

	check_print(result, board, expected);

	ASSERT_TRUE(result);
}

TEST(move_right, simple_move_right_no_merge)
{
	Board board;

	int initial[4][4] = {
		{2, 4, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};
	int expected[4][4] = {
		{0, 0, 2, 4},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};

	load_board(board, initial);
	move_right(board);
	bool result = compare_board(board, expected);

	check_print(result, board, expected);

	ASSERT_TRUE(result);
}

TEST(move_right, simple_move_right_with_merge)
{
	Board board;

	int initial[4][4] = {
		{2, 2, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};
	int expected[4][4] = {
		{0, 0, 0, 4},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};

	load_board(board, initial);
	move_right(board);
	bool result = compare_board(board, expected);

	check_print(result, board, expected);

	ASSERT_TRUE(result);
}

TEST(move_right, complex_move_right)
{
	Board board;

	int initial[4][4] = {
		{2, 0, 0, 0},
		{0, 0, 2, 0},
		{0, 0, 0, 2},
		{0, 2, 0, 0}
	};
	int expected[4][4] = {
		{0, 0, 0, 2},
		{0, 0, 0, 2},
		{0, 0, 0, 2},
		{0, 0, 0, 2}
	};

	load_board(board, initial);
	move_right(board);
	bool result = compare_board(board, expected);

	check_print(result, board, expected);

	ASSERT_TRUE(result);
}

TEST(move_right, complex_move_right_no_merge)
{
	Board board;

	int initial[4][4] = {
		{2, 4, 0, 0},
		{0, 4, 2, 0},
		{0, 4, 0, 2},
		{0, 2, 0, 4}
	};
	int expected[4][4] = {
		{0, 0, 2, 4},
		{0, 0, 4, 2},
		{0, 0, 4, 2},
		{0, 0, 2, 4}
	};

	load_board(board, initial);
	move_right(board);
	bool result = compare_board(board, expected);

	check_print(result, board, expected);

	ASSERT_TRUE(result);
}

TEST(move_right, complex_move_right_with_merge)
{
	Board board;

	int initial[4][4] = {
		{4, 4, 0, 0},
		{0, 2, 2, 2},
		{0, 0, 2, 2},
		{2, 2, 2, 2}
	};
	int expected[4][4] = {
		{0, 0, 0, 8},
		{0, 0, 2, 4},
		{0, 0, 0, 4},
		{0, 0, 4, 4}
	};

	load_board(board, initial);
	move_right(board);
	bool result = compare_board(board, expected);

	check_print(result, board, expected);

	ASSERT_TRUE(result);
}

//TESTS move up
TEST(move_up, simple_move_up)
{
	Board board;

	int initial[4][4] = {
		{0, 0, 0, 0},
		{2, 0, 0, 0},
		{0, 0, 2, 0},
		{0, 0, 0, 0}
	};
	int expected[4][4] = {
		{2, 0, 2, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};

	load_board(board, initial);
	move_up(board);
	bool result = compare_board(board, expected);

	check_print(result, board, expected);
	ASSERT_TRUE(result);
}

TEST(move_up, simple_move_up_no_merge)
{
	Board board;

	int initial[4][4] = {
		{0, 0, 0, 0},
		{2, 0, 0, 0},
		{4, 0, 0, 0},
		{0, 0, 0, 0}
	};
	int expected[4][4] = {
		{2, 0, 0, 0},
		{4, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};

	load_board(board, initial);
	move_up(board);
	bool result = compare_board(board, expected);

	check_print(result, board, expected);
	ASSERT_TRUE(result);
}

TEST(move_up, simple_move_up_with_merge)
{
	Board board;

	int initial[4][4] = {
		{0, 0, 0, 0},
		{2, 0, 0, 0},
		{2, 0, 0, 0},
		{0, 0, 0, 0}
	};
	int expected[4][4] = {
		{4, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};

	load_board(board, initial);
	move_up(board);
	bool result = compare_board(board, expected);

	check_print(result, board, expected);
	ASSERT_TRUE(result);
}

TEST(move_up, complex_move_up)
{
	Board board;

	int initial[4][4] = {
		{0, 0, 0, 2},
		{0, 0, 2, 0},
		{0, 2, 0, 0},
		{2, 0, 0, 0}
	};
	int expected[4][4] = {
		{2, 2, 2, 2},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};

	load_board(board, initial);
	move_up(board);
	bool result = compare_board(board, expected);

	check_print(result, board, expected);
	ASSERT_TRUE(result);
}

TEST(move_up, complex_move_up_no_merge)
{
	Board board;

	int initial[4][4] = {
		{0, 0, 0, 0},
		{0, 4, 0, 4},
		{0, 2, 4, 2},
		{2, 4, 2, 0}
	};
	int expected[4][4] = {
		{2, 4, 4, 4},
		{0, 2, 2, 2},
		{0, 4, 0, 0},
		{0, 0, 0, 0}
	};

	load_board(board, initial);
	move_up(board);
	bool result = compare_board(board, expected);

	check_print(result, board, expected);
	ASSERT_TRUE(result);
}

TEST(move_up, complex_move_up_with_merge)
{
	Board board;

	int initial[4][4] = {
		{0, 2, 2, 2},
		{0, 2, 2, 0},
		{4, 2, 0, 0},
		{4, 0, 0, 0}
	};
	int expected[4][4] = {
		{8, 4, 4, 2},
		{0, 2, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};

	load_board(board, initial);
	move_up(board);
	bool result = compare_board(board, expected);

	check_print(result, board, expected);
	ASSERT_TRUE(result);
}

//TESTS move down
TEST(move_down, simple_move_down)
{
	Board board;

	int initial[4][4] = {
		{2, 0, 0, 0},
		{0, 0, 2, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};
	int expected[4][4] = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{2, 0, 2, 0}
	};

	load_board(board, initial);
	move_down(board);
	bool result = compare_board(board, expected);

	check_print(result, board, expected);
	ASSERT_TRUE(result);
}

TEST(move_down, simple_move_down_no_merge)
{
	Board board;

	int initial[4][4] = {
		{2, 0, 0, 0},
		{4, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};
	int expected[4][4] = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{2, 0, 0, 0},
		{4, 0, 0, 0}
	};

	load_board(board, initial);
	move_down(board);
	bool result = compare_board(board, expected);

	check_print(result, board, expected);
	ASSERT_TRUE(result);
}

TEST(move_down, simple_move_down_with_merge)
{
	Board board;

	int initial[4][4] = {
		{2, 0, 0, 0},
		{2, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};
	int expected[4][4] = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{4, 0, 0, 0}
	};

	load_board(board, initial);
	move_down(board);
	bool result = compare_board(board, expected);

	check_print(result, board, expected);
	ASSERT_TRUE(result);
}

TEST(move_down, complex_move_down)
{
	Board board;

	int initial[4][4] = {
		{2, 0, 0, 0},
		{0, 2, 0, 0},
		{0, 0, 2, 0},
		{0, 0, 0, 2}
	};
	int expected[4][4] = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{2, 2, 2, 2}
	};

	load_board(board, initial);
	move_down(board);
	bool result = compare_board(board, expected);

	check_print(result, board, expected);
	ASSERT_TRUE(result);
}

TEST(move_down, complex_move_down_no_merge)
{
	Board board;

	int initial[4][4] = {
		{2, 4, 0, 2},
		{0, 2, 2, 4},
		{4, 4, 0, 2},
		{0, 2, 4, 4}
	};
	int expected[4][4] = {
		{0, 4, 0, 2},
		{0, 2, 0, 4},
		{2, 4, 2, 2},
		{4, 2, 4, 4}
	};

	load_board(board, initial);
	move_down(board);
	bool result = compare_board(board, expected);

	check_print(result, board, expected);
	ASSERT_TRUE(result);
}

TEST(move_down, complex_move_down_with_merge)
{
	Board board;

	int initial[4][4] = {
		{4, 0, 0, 2},
		{4, 2, 0, 2},
		{2, 2, 2, 4},
		{0, 2, 2, 4}
	};
	int expected[4][4] = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{8, 2, 0, 4},
		{2, 4, 4, 8}
	};

	load_board(board, initial);
	move_down(board);
	bool result = compare_board(board, expected);

	check_print(result, board, expected);
	ASSERT_TRUE(result);
}

TEST(set_new_tile_after_movement, set_new_tile_after_move_and_check_value)
{
	Board board;
	int	counter = 0;	
	int x = 0;
	int y = 0;
	int	new_tile_value = 0;
	int expected = 13;


	int initial[4][4] = {
		{4, 0, 0, 2},
		{4, 2, 0, 2},
		{2, 2, 2, 4},
		{0, 2, 2, 4}
	};

	load_board(board, initial);
	set_new_tile_after_movement(board);
	
	while (x < 4)
	{
		while (y < 4)
		{
			if (board.grid_at(x, y).get_value() != 0)
				counter++;
			if (initial[x][y] == 0 && board.grid_at(x, y).get_value() != 0)
				new_tile_value = board.grid_at(x, y).get_value();
			y++;
		}
		y = 0;
		x++;
	}

	ASSERT_EQ(counter, expected);
	ASSERT_TRUE(new_tile_value == 2 || new_tile_value == 4);

}






