#ifndef RENDER_BOARD_HPP
# define RENDER_BOARD_HPP

#include "render_tile.hpp"
#include <vector>
#include <iostream>

class RenderBoard
{
	private:
		sf::RenderWindow window;
		std::vector<RenderTile> tiles_renderizados;
		sf::Font font;
		TileColors colors;
		sf::Event event;

	public:
		RenderBoard(Board &board);
		void RenderBoard::game_loop();
};


#endif