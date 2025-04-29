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

TEST(move_left, multiple_merge_with_different_values)
{
	Board board;

	int initial[4][4] = {
		{4, 4, 32, 32},
		{128, 128, 0, 2},
		{64, 64, 16, 16},
		{2, 256, 256, 2}
	};
	int expected[4][4] = {
		{8, 64, 0, 0},
		{256, 2, 0, 0},
		{128, 32, 0, 0},
		{2, 512, 2, 0}
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

TEST(move_right, multiple_merge_with_different_values)
{
	Board board;

	int initial[4][4] = {
		{8,   8,   32,  32},
		{128, 128, 0,   2},
		{64,  64,  16,  16},
		{2,   256, 256, 2}
	};
	int expected[4][4] = {
		{0, 0, 16,  64},
		{0, 0, 256, 2},
		{0, 0, 128, 32},
		{0, 2, 512, 2}
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

TEST(move_up, multiple_merge_with_different_values)
{
	Board board;

	int initial[4][4] = {
		{128, 8,   256, 64},
		{128, 32,  256, 64},
		{64,  32,  4,   2},
		{2,   256, 4,   2}
	};
	int expected[4][4] = {
		{256, 8,   512, 128},
		{64,  64,  8,   4},
		{2,   256, 0,   0},
		{0,   0,   0,   0}
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

TEST(move_down, multiple_merge_with_different_values)
{
	Board board;

	int initial[4][4] = {
		{128, 8,   256, 64},
		{128, 32,  256, 64},
		{64,  32,  4,   2},
		{2,   256, 4,   2}
	};
	int expected[4][4] = {
		{0,   0,   0,   0},
		{256, 8,   0,   0},
		{64,  64,  512, 128},
		{2,   256, 8,   4}
	};

	load_board(board, initial);
	move_down(board);
	bool result = compare_board(board, expected);

	check_print(result, board, expected);

	ASSERT_TRUE(result);
}

//TEST new random tile after move
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
	board.set_new_tile_after_movement();
	
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

//TEST updating score
TEST(update_score, score_increases_correctly_after_move_left)
{
	Board board;
	int expected = 20;

	int initial[4][4] = {
		{4, 4, 0, 2}, //4 + 4 = 8
		{4, 2, 0, 2}, //2 + 2 = 4
		{2, 2, 2, 4}, //2 + 2 = 4
		{0, 2, 2, 4}  //2 + 2 = 4
	};

	ASSERT_EQ(board.get_score(), 0); //verificação se o score estava 0

	load_board(board, initial);
	move_left(board);
	
	ASSERT_EQ(board.get_score(), expected);
}

//TEST checking game over
TEST(can_move, board_with_possible_moves)
{
	Board board;
	
	int initial[4][4] = {
		{4, 2, 0, 2},
		{4, 2, 4, 2},
		{2, 2, 2, 4},
		{2, 2, 2, 4}
	};

	load_board(board, initial);

	EXPECT_TRUE(board.can_move());
}

TEST(can_move, board_with_no_possible_moves)
{
	Board board;
	
	int initial[4][4] = {
		{4, 2, 4, 2},
		{2, 4, 2, 4},
		{4, 2, 4, 2},
		{2, 4, 2, 4}
	};

	load_board(board, initial);

	EXPECT_FALSE(board.can_move());
}

TEST(can_move, board_with_possible_col_merge)
{
	Board board;
	
	int initial[4][4] = {
		{4, 2, 4, 2},
		{2, 4, 2, 4},
		{4, 8, 2, 8},
		{2, 4, 2, 2}
	};

	load_board(board, initial);

	EXPECT_TRUE(board.can_move());
}

TEST(can_move, board_with_possible_row_merge)
{
	Board board;
	
	int initial[4][4] = {
		{4, 2, 4, 2},
		{2, 4, 2, 8},
		{4, 2, 4, 4},
		{2, 4, 2, 2}
	};

	load_board(board, initial);

	EXPECT_TRUE(board.can_move());
}

TEST(can_move, board_with_no_possible_merge)
{
	Board board;
	
	int initial[4][4] = {
		{4, 2, 4, 2},
		{2, 4, 2, 4},
		{4, 2, 4, 2},
		{2, 4, 2, 4}
	};

	load_board(board, initial);

	EXPECT_FALSE(board.can_move());
}

//TEST undo
TEST(undo, simple_undo)
{
	Board board;
	
	int initial[4][4] = {
		{2, 2, 4, 4}, // 0 0 4 8
		{2, 2, 2, 2}, // 0 0 4 4
		{4, 0, 4, 0}, // 0 0 4 4
		{2, 2, 2, 4}  // 0 0 4 4
	};

	int expected[4][4] = {
		{2, 2, 4, 4},
		{2, 2, 2, 2},
		{4, 0, 4, 0},
		{2, 2, 2, 4}
	};

	load_board(board, initial);
	board.save_history();
	move_right(board);
	board.undo();

	ASSERT_TRUE(compare_board(board, expected));
}

TEST(undo, simple_undo_after_2_moves)
{
	Board board;
	
	int initial[4][4] = {
		{2, 2, 4, 4}, // 0 0 4 8  // 0 0 0 0
		{2, 2, 2, 2}, // 0 0 4 4  // 0 0 0 8
		{4, 0, 4, 0}, // 0 0 0 8  // 0 0 8 4
		{2, 2, 2, 4}  // 0 2 4 4  // 0 0 8 8
	};

	int expected[4][4] = {
		{0, 0, 4, 8},
		{0, 0, 4, 4},
		{0, 0, 0, 8},
		{0, 2, 4, 4}
	};

	load_board(board, initial);
	board.save_history();
	move_right(board);
	board.save_history();
	move_down(board);
	board.undo();
	
	ASSERT_TRUE(compare_board(board, expected));

}

TEST(undo, simple_undo_after_3_moves)
{
	Board board;
	
	int initial[4][4] = {
		{2, 2, 4, 4}, // 0 0 4 8    // 0 0 0 8
		{2, 2, 2, 2}, // 0 0 4 4    // 0 0 0 4
		{4, 0, 4, 0}, // 0 0 0 8    // 0 0 4 8
		{2, 2, 2, 4}  // 0 2 4 4    // 0 2 8 4
	};				  //move_right  //move_down

	int expected[4][4] = {
		{0, 0, 0, 8},
		{0, 0, 0, 4},
		{0, 0, 4, 8},
		{0, 2, 8, 4}
	};

	load_board(board, initial);
	board.save_history();
	move_right(board);
	board.save_history();
	move_down(board);
	board.save_history();
	move_up(board);
	board.undo();

	ASSERT_TRUE(compare_board(board, expected));

}

TEST(undo, 5_times_undo_after_5_moves)
{
	Board board;
	
	int initial[4][4] = {
		{2, 2, 4, 4},     // 0 0 8 8     // 0 0 0 8   // 0 2 16 8  // 0 2 16 8  // 2 16 8 0
		{2, 2, 2, 2},     // 0 0 4 4     // 0 0 0 4   // 0 0 0  4  // 0 0 0  4  // 4  0 0 0
		{4, 0, 4, 0},     // 0 0 0 8     // 0 0 8 8   // 0 0 0  8  // 0 0 0  8  // 8  0 0 0
		{2, 2, 2, 4}      // 0 2 4 4     // 0 2 8 4   // 0 0 0  4  // 0 0 0  4  // 4  0 0 0
	};                    //move_ right  //move_down  //move_up    //move_down  //move_left

	int expected[4][4] = {
		{2, 2, 4, 4},
		{2, 2, 2, 2},
		{4, 0, 4, 0},
		{2, 2, 2, 4}
	};

	load_board(board, initial);
	board.save_history();
	move_right(board);
	board.save_history();
	move_down(board);
	board.save_history();
	move_up(board);
	board.save_history();
	move_right(board);
	board.save_history();
	move_left(board);
	board.undo();
	board.undo();
	board.undo();
	board.undo();
	board.undo();

	ASSERT_TRUE(compare_board(board, expected));
}

TEST(undo, new_move_in_middle_of_history_check_previous)
{
	Board board;
	
	int initial[4][4] = {
		{4, 4, 4, 4}, // 0 0 8 8    // 0 0 0  8  // 0 2 8  8
		{4, 4, 2, 2}, // 0 0 8 4    // 0 0 8  4  // 0 0 16 4
		{4, 4, 4, 4}, // 0 0 8 8    // 0 0 16 8  // 0 0 4  8
		{2, 2, 2, 4}  // 0 2 4 4    // 0 2 4  4  // 0 0 0  4
	};				  //move_right  //move_down  // move_up

	int expected1[4][4] = {
		{0, 2, 8, 8},
		{0, 0, 16, 4},
		{0, 0, 4, 8},
		{0, 0, 0, 4}
	};

	int expected2[4][4] = {
		{0, 0, 0, 8},   // 2  16 0 0
		{0, 0, 8, 4},  // 16 4  0 0
		{0, 0, 16, 8},   // 4  8  0 0
		{0, 2, 4, 4}    // 4  0  0 0
	};					//move_left

	load_board(board, initial);
	board.save_history();
	move_right(board);
	board.save_history();
	move_down(board);
	board.save_history();
	move_up(board);
	board.save_history();
	move_down(board);
	board.save_history();
	move_right(board);
	board.undo();
	board.undo();

	//board.print_table();

	EXPECT_TRUE(compare_board(board, expected1));

	board.save_history();
	move_left(board);
	board.undo();
	board.undo();

	//board.print_table();

	EXPECT_TRUE(compare_board(board, expected2));

}

TEST(undo, calling_undo_more_than_5_times)
{
	Board board;
	bool arr[5];
	
	int initial[4][4] = {
		{2, 2, 4, 4},
		{2, 2, 2, 2},
		{4, 0, 4, 0},
		{2, 2, 2, 4}  
	};                   

	load_board(board, initial);
	board.save_history();
	move_right(board);
	board.save_history();
	move_down(board);
	board.save_history();
	move_up(board);
	board.save_history();
	move_right(board);
	board.save_history();
	move_left(board);
	board.save_history();
	move_left(board);
	arr[0] = board.undo();
	arr[1] = board.undo();
	arr[2] = board.undo();
	arr[3] = board.undo();
	arr[4] = board.undo();
	arr[5] = board.undo();

	EXPECT_TRUE(arr[0]);
	EXPECT_TRUE(arr[1]);
	EXPECT_TRUE(arr[2]);
	EXPECT_TRUE(arr[3]);
	EXPECT_TRUE(arr[4]);
	EXPECT_FALSE(arr[5]);

}

//TEST new_game
TEST(new_game, call_new_game_and_check_values)
{
	Board board;
	bool arr[5];
	
	int initial[4][4] = {
		{2, 2, 4, 4},
		{2, 2, 2, 2},
		{4, 0, 4, 0},
		{2, 2, 2, 4}  
	};  

	load_board(board, initial);

	int undo_expect = 5;
	int score_expect = 0;
	int	tiles_counter = 0;
	int x = 0;
	int y = 0;

	board.new_game();

	while (x < 4)
	{
		while (y < 4)
		{
			if (board.grid_at(x, y).get_value() != 0)
			tiles_counter++;
			if (initial[x][y] == 0 && board.grid_at(x, y).get_value() != 0)
			tiles_counter = board.grid_at(x, y).get_value();
			y++;
		}
		y = 0;
		x++;
	}

	EXPECT_EQ(board.get_undo_counter(), undo_expect);
	EXPECT_EQ(board.get_score(), score_expect);
	EXPECT_TRUE(tiles_counter == 2);


}