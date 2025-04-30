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
	
	RenderBoard rendered_board(board);
	
	GameControl game_control(board, rendered_board);
	
	game_control.game_loop();


    return 0;
}
