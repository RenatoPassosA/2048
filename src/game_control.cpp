
#include "game_control.hpp"
#include "../graphics/render_board.hpp"

GameControl::GameControl()
{
	window.create(sf::VideoMode(500, 600), "2048", sf::Style::Default);
}

void GameControl::game_loop(Board &board, RenderBoard &board_render)
{
	while (window.isOpen())
    {
        // Verificar todos os eventos da janela que ocorreram desde a última iteração
        while (window.pollEvent(event))
            check_event_type(event, board);
		
		board_render.update(board);
		
		window.clear(sf::Color(250, 248, 239)); // Cor de fundo do 2048
		
        for (RenderTile &tile : board_render.get_tiles()) {
            tile.draw(this->getWindow());
        }
		
		board_render.draw_score(window, board);
		board_render.draw_new_game(window);
		window.display();
    }
}

void	GameControl::check_event_type(sf::Event event, Board &board)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Up)
			board.handle_direction(Direction::up);
		else if (event.key.code == sf::Keyboard::Down)
			board.handle_direction(Direction::down);
		else if (event.key.code == sf::Keyboard::Left)
			board.handle_direction(Direction::left);
		else if (event.key.code == sf::Keyboard::Right)
			board.handle_direction(Direction::right);
	}
	else if (event.type == sf::Event::Closed)
		window.close();
}

sf::RenderWindow &GameControl::getWindow()
{
    return window;
}




