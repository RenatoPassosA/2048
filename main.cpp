#include "./game.hpp"
#include "./tests/tests.hpp"

#include <SFML/Window.hpp>

int main()
{
	// carrega o board para teste
	Board board;
	
	/*int initial[4][4] = {
		{0, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};

	load_board(board, initial);*/

	RenderBoard init_board(board);
	GameControl game_control;
	
	game_control.game_loop(board, init_board);


    return 0;
}
