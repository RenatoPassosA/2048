#ifndef GAME_CONTROL_HPP
# define GAME_CONTROL_HPP

#include "../graphics/render_board.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class GameControl
{
	private:
		sf::RenderWindow window;
		sf::Event event;

	public:
		GameControl();
		void				game_loop(Board &board, RenderBoard &board_render);
		sf::RenderWindow	&getWindow();
		void				check_event_type(sf::Event event, Board &board);
};

#endif