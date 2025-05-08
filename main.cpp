#include "./game.hpp"
#include "./tests/tests.hpp"

#include <SFML/Window.hpp>

int main()
{
	Board board;
	
	// carrega o board para teste
	/*int initial[4][4] = {
		{65536, 2, 4, 8},
		{128, 64, 32, 16},
		{256, 512, 1024, 2048},
		{4096, 8192, 16384, 32768}
	};

	load_board(board, initial);*/
	
	RenderBoard rendered_board(board);
	
	GameControl game_control(board, rendered_board);
	
	game_control.game_loop();


    return 0;
}
