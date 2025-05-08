
#include "game_control.hpp"
#include "../graphics/render_board.hpp"

GameControl::GameControl(Board &board, RenderBoard &board_render)
	:board_ref(board), rendered_board_ref(board_render)
{
	window.create(sf::VideoMode(500, 600), "2048", sf::Style::Titlebar | sf::Style::Close);
}

void GameControl::game_loop()
{
	
	while (window.isOpen())
    {
        while (window.pollEvent(event))
            check_event_type(event);
		rendered_board_ref.update_all_tiles();
		rendered_board_ref.update_score(window);
		window.clear(sf::Color(250, 248, 239));
		rendered_board_ref.draw_all(window);
		if (!board_ref.check_end_game())
			rendered_board_ref.set_game_over(window);
		window.display();
    }
}

void	GameControl::check_event_type(sf::Event event)
{
	

	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Up)
			board_ref.handle_direction(Direction::up);
		else if (event.key.code == sf::Keyboard::Down)
			board_ref.handle_direction(Direction::down);
		else if (event.key.code == sf::Keyboard::Left)
			board_ref.handle_direction(Direction::left);
		else if (event.key.code == sf::Keyboard::Right)
			board_ref.handle_direction(Direction::right);
	}
	else if (event.type == sf::Event::Closed)
	{
		window.close();
	}
	else if (event.type == sf::Event::MouseButtonPressed &&	event.mouseButton.button == sf::Mouse::Left)
	{
		sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

		if (rendered_board_ref.get_new_game_button().getGlobalBounds().contains(mousePos))
		{
			window.clear();
			board_ref.reset_undo_counter();
			board_ref.delete_history();
			board_ref.new_game();
		}
		if (rendered_board_ref.get_undo_button().getGlobalBounds().contains(mousePos))
		{
			if (!board_ref.has_history())
				return ;
			board_ref.undo();
		}
	}
}

sf::RenderWindow &GameControl::get_window()
{
    return window;
}
