#ifndef RENDER_BOARD_HPP
# define RENDER_BOARD_HPP

#include "render_tile.hpp"
#include <vector>
#include <iostream>

class TileColors {
	private:
		std::unordered_map<int, sf::Color>	colorMap; //unordered_map é a mesma coisa que o dict
	
	public:
		TileColors();
		sf::Color	getColor(int value);
};

class RenderBoard
{
	private:
		std::vector<RenderTile> tiles_renderizados;
		TileColors colors;
		sf::Font font;
		sf::RectangleShape background_panel;
		sf::Text score_val_text;
		sf::RectangleShape new_game_button;
		sf::Text new_game_text;

	public:
		RenderBoard(Board &board);
		std::vector<RenderTile>	&get_tiles();
		void					draw_score(sf::RenderWindow& window, Board &board);
		void					draw_new_game(sf::RenderWindow& window);
		void					update(Board &board);
		
		
		
};


#endif