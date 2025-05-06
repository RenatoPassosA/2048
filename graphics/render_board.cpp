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

	for (auto &tile : get_tiles())
		tile.draw(window);


    window.draw(background_score_panel);

    
    window.draw(score_val_panel_text);
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
			//std::cout << "Tile Position for (" << board.grid_at(x, y).get_x() << ", " << board.grid_at(x, y).get_y() << "): value:" << board.grid_at(x, y).get_value() << std::endl; 
			y++;
		}
		y = 0;
		x++;
	}
}

void RenderBoard::set_score_panel(sf::RenderWindow &window)
{
    std::string score = std::to_string(board_ref.get_score());

    // Configurar o texto para o score
    score_val_panel_text.setFont(font);
    score_val_panel_text.setCharacterSize(30); // Tamanho da fonte para o score
    score_val_panel_text.setString(score); // Texto com o score
    score_val_panel_text.setFillColor(sf::Color::Black);

    // Calcular o tamanho e a posição do retângulo de fundo
    float window_width = window.getSize().x;
    float panel_width = window_width - 100.f; // Painel com largura fixa (margem de 50px em cada lado)
    float panel_height = 75.f; // Altura do painel (ajuste conforme necessário)
    float posY = 10.f; // Posição Y do retângulo (ajuste conforme necessário)

    // Calcular a posição X para centralizar o painel
    float posX = 50.f; // Margin left de 50px (ajuste conforme necessário)

    // Configurar o retângulo de fundo
    background_score_panel.setSize(sf::Vector2f(panel_width, panel_height));
    background_score_panel.setFillColor(sf::Color::White); // Cor do painel de fundo
    background_score_panel.setPosition(posX, posY); // Posicionar o painel na parte superior da tela
	background_score_panel.setOutlineThickness(2.f);
    background_score_panel.setOutlineColor(sf::Color(150, 150, 150));

    // Ajustar a posição do texto para centralizá-lo dentro do retângulo
	sf::FloatRect textBounds = score_val_panel_text.getLocalBounds();
    score_val_panel_text.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    score_val_panel_text.setPosition(posX + panel_width / 2, posY + panel_height / 2); // Centralizar o texto dentro do retângulo

}
