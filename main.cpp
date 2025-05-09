#include "./game.hpp"
#include "./tests/tests.hpp"

#include <SFML/Window.hpp>

int main()
{
	Board board;
	
	RenderBoard rendered_board(board);
	GameControl game_control(board, rendered_board);
	game_control.game_loop();

    return 0;
}
