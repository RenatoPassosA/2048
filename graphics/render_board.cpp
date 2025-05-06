#include "render_board.hpp"

/*
Gerenciar todos os RenderTile de uma vez;

Atualizar e desenhar todos eles em um loop (sem ter esse código disperso no main);

Centralizar o controle da renderização da parte gráfica do jogo.
*/

std::vector<RenderTile> &RenderBoard::get_tiles()
{
	return (tiles_renderizados);
}

void RenderBoard::draw_all(sf::RenderWindow	&window)
{
	set_score_panel(window);
	set_new_game_button(window);
	set_undo_button(window);

	for (auto &tile : get_tiles())
		tile.draw(window);


    window.draw(background_score_panel);
    window.draw(score_val_panel_text);
	window.draw(new_game_button);
    window.draw(new_game_button_text);
	window.draw(undo_button);
    window.draw(undo_button_text);

};

void RenderBoard::update_all_tiles()
{
	for (auto &tile: tiles_renderizados)
		tile.update_visual();
};

void RenderBoard::update_score(sf::RenderWindow &window)
{
	float window_width = window.getSize().x;
    float panel_width = window_width - 100.f;
    float panel_height = 75.f;
    float posY = 10.f;
	float posX = 50.f;

	int value = board_ref.get_score();
	score_val_panel_text.setString(std::to_string(value));
	sf::FloatRect textBounds = score_val_panel_text.getLocalBounds();
    score_val_panel_text.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    score_val_panel_text.setPosition(posX + panel_width / 2, posY + panel_height / 2);
};

RenderBoard::RenderBoard(Board &board)
	: board_ref(board)
{
	if (!font.loadFromFile("assets/fonts/press-start-2p.ttf"))
		exit(1);

	int y = 0;
	int x = 0;
	while (x < 4)
	{
		while (y < 4)
		{
			tiles_renderizados.emplace_back(board.grid_at(x, y), colors, font);
			y++;
		}
		y = 0;
		x++;
	}
}

void RenderBoard::set_score_panel(sf::RenderWindow &window)
{
    std::string score = std::to_string(board_ref.get_score());

    score_val_panel_text.setFont(font);
    score_val_panel_text.setCharacterSize(30);
    score_val_panel_text.setString(score);
    score_val_panel_text.setFillColor(sf::Color::Black);

    float window_width = window.getSize().x;
    float panel_width = window_width - 100.f;
    float panel_height = 75.f;
    float posY = 10.f;
    float posX = 50.f;

    background_score_panel.setSize(sf::Vector2f(panel_width, panel_height));
    background_score_panel.setFillColor(sf::Color::White);
    background_score_panel.setPosition(posX, posY);
	background_score_panel.setOutlineThickness(2.f);
    background_score_panel.setOutlineColor(sf::Color(150, 150, 150));

	sf::FloatRect textBounds = score_val_panel_text.getLocalBounds();
    score_val_panel_text.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    score_val_panel_text.setPosition(posX + panel_width / 2, posY + panel_height / 2);
}

void RenderBoard::set_new_game_button(sf::RenderWindow &window)
{
    new_game_button_text.setFont(font);
    new_game_button_text.setCharacterSize(10);
    new_game_button_text.setString("New  Game");
    new_game_button_text.setFillColor(sf::Color::Black);

    float window_width = window.getSize().x;
    float window_height = window.getSize().y;
    float button_width = 100.f;
    float button_height = 50.f;
    float bottom_margin = 10.f;
	float right_margin = 100.f;

	float posX = window_width - button_width - right_margin;
	float posY = window_height - button_height - bottom_margin;

    new_game_button.setSize(sf::Vector2f(button_width, button_height));
    new_game_button.setFillColor(sf::Color::White);
    new_game_button.setOutlineThickness(2.f);
    new_game_button.setOutlineColor(sf::Color(150, 150, 150));
    new_game_button.setPosition(posX, posY);

    sf::FloatRect textBounds = new_game_button_text.getLocalBounds();
    new_game_button_text.setOrigin(textBounds.left + textBounds.width / 2.0f,
                                   textBounds.top + textBounds.height / 2.0f);
    new_game_button_text.setPosition(posX + button_width / 2.f, posY + button_height / 2.f);
}

const sf::RectangleShape &RenderBoard::get_new_game_button() const
{
    return new_game_button;
}

void	RenderBoard::set_undo_button(sf::RenderWindow& window)
{
	undo_button_text.setFont(font);
    undo_button_text.setCharacterSize(10);
    undo_button_text.setString("Desfazer");
    undo_button_text.setFillColor(sf::Color::Black);

    float window_height = window.getSize().y;
    float button_width = 100.f;
    float button_height = 50.f;
    float bottom_margin = 10.f;

	float posX = button_width;
	float posY = window_height - button_height - bottom_margin;

    undo_button.setSize(sf::Vector2f(button_width, button_height));
    undo_button.setFillColor(sf::Color::White);
    undo_button.setOutlineThickness(2.f);
    undo_button.setOutlineColor(sf::Color(150, 150, 150));
    undo_button.setPosition(posX, posY);

    sf::FloatRect textBounds = undo_button_text.getLocalBounds();
    undo_button_text.setOrigin(textBounds.left + textBounds.width / 2.0f,
                                   textBounds.top + textBounds.height / 2.0f);
    undo_button_text.setPosition(posX + button_width / 2.f, posY + button_height / 2.f);
};

const sf::RectangleShape &RenderBoard::get_undo_button() const
{
    return undo_button;
}

