#ifndef GAME_CONTROL_HPP
# define GAME_CONTROL_HPP

#include "../graphics/render_board.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class GameControl
{
	private:
		sf::RenderWindow	window;
		sf::Event			event;
		Board				&board_ref;
		RenderBoard			&rendered_board_ref;

	public:
		GameControl(Board &board, RenderBoard &rendered_board);
		void				game_loop();
		sf::RenderWindow	&get_window();
		void				check_event_type(sf::Event event);
};

#endif