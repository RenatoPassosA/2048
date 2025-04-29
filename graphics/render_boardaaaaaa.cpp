#include "render_board.hpp"

RenderBoard::RenderBoard(Board &board)
{
	//carregamento da fonte
	if (!font.loadFromFile("assets/fonts/press-start-2p.ttf"))
	{
		std::cerr << "ERRO: Fonte não carregada em: " << "assets/fonts/press-start-2p.ttf" << std::endl;
		exit(1);
	}

	//criação de todos os tiles
	for (int x = 0; x < 4; ++x)
	{
		for (int y = 0; y < 4; ++y)
			tiles_renderizados.emplace_back(board, colors, font, y, x);
	}
	
}

std::vector<RenderTile> &RenderBoard::get_tiles()
{
	return (tiles_renderizados);
}

void RenderBoard::draw_score(sf::RenderWindow& window, Board &board)
{
    std::string score = std::to_string(board.get_score());

    // Configurar o texto para o score
    score_val_text.setFont(font);
    score_val_text.setCharacterSize(30); // Tamanho da fonte para o score
    score_val_text.setString(score); // Texto com o score
    score_val_text.setFillColor(sf::Color::Black);

    // Calcular o tamanho e a posição do retângulo de fundo
    float window_width = window.getSize().x;
    float panel_width = window_width - 100.f; // Painel com largura fixa (margem de 50px em cada lado)
    float panel_height = 75.f; // Altura do painel (ajuste conforme necessário)
    float posY = 10.f; // Posição Y do retângulo (ajuste conforme necessário)

    // Calcular a posição X para centralizar o painel
    float posX = 50.f; // Margin left de 50px (ajuste conforme necessário)

    // Configurar o retângulo de fundo
    background_panel.setSize(sf::Vector2f(panel_width, panel_height));
    background_panel.setFillColor(sf::Color::White); // Cor do painel de fundo
    background_panel.setPosition(posX, posY); // Posicionar o painel na parte superior da tela
	background_panel.setOutlineThickness(2.f);
    background_panel.setOutlineColor(sf::Color(150, 150, 150));

    // Ajustar a posição do texto para centralizá-lo dentro do retângulo
    sf::FloatRect textBounds = score_val_text.getLocalBounds();
    score_val_text.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    score_val_text.setPosition(posX + panel_width / 2, posY + panel_height / 2); // Centralizar o texto dentro do retângulo

    // Desenhar o retângulo de fundo
    window.draw(background_panel);

    // Desenhar o texto do score
    window.draw(score_val_text);
}
void RenderBoard::draw_new_game(sf::RenderWindow& window)
{
	new_game_button.setSize(sf::Vector2f(170.f, 50.f));  // Tamanho fixo do botão
	new_game_button.setFillColor(sf::Color(100, 100, 250));  // Cor do botão
	new_game_button.setOutlineThickness(2.f);
	new_game_button.setOutlineColor(sf::Color::Black);  // Cor da borda do botão

	// Configuração do texto
	new_game_text.setFont(font);
	new_game_text.setCharacterSize(20);  // Tamanho da fonte
	new_game_text.setString("New Game");  // Texto do botão
	new_game_text.setFillColor(sf::Color::White);  // Cor do texto

	float window_width = window.getSize().x;
	float window_height = window.getSize().y;

	float button_width = new_game_button.getSize().x;
	float button_height = new_game_button.getSize().y;

	float posX = (window_width - button_width) / 2.f;  // Centraliza horizontalmente
	float posY = window_height - button_height - 10.f;  // Coloca abaixo do painel de score com um pequeno espaço

	new_game_button.setPosition(posX, posY);

	// Centralizando o texto dentro do botão
	sf::FloatRect textBounds = new_game_text.getLocalBounds();
	new_game_text.setOrigin(textBounds.left + textBounds.width / 2.f, textBounds.top + textBounds.height / 2.f);
	new_game_text.setPosition(posX + button_width / 2.f, posY + button_height / 2.f);  // Centraliza o texto no botão


	window.draw(new_game_button);
	window.draw(new_game_text);
}

void RenderBoard::update(Board &board)
{
	for (auto &tile : tiles_renderizados)
		tile.update();
}
