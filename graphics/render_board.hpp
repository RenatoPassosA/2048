#ifndef RENDER_BOARD_HPP
# define RENDER_BOARD_HPP

#include "render_tile.hpp"
#include <vector>
#include <iostream>




class RenderBoard
{
	private:
		Board &board_ref;
		std::vector<RenderTile> tiles_renderizados;

		TileColors colors;
		sf::Font font;

		sf::RectangleShape background_score_panel;
		sf::Text score_val_panel_text;
		/*sf::RectangleShape new_game_button;
		sf::Text new_game_button_text;*/

	public:
		RenderBoard(Board &board);
		std::vector<RenderTile>	&get_tiles();
		void					set_score_panel(sf::RenderWindow &window);
		/*void					draw_new_game(sf::RenderWindow& window);*/
		void					draw_all(sf::RenderWindow &window);
		void					update_all_tiles();
		void					update_score(sf::RenderWindow &window);
		
		
		
};


#endif