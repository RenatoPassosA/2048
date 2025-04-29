#include "render_tile.hpp"

TileColors::TileColors()
{
	colorMap = {
		{0,    sf::Color(205, 193, 180)},
		{2,    sf::Color(238, 228, 218)},
		{4,    sf::Color(237, 224, 200)},
		{8,    sf::Color(242, 177, 121)},
		{16,   sf::Color(245, 149, 99)},
		{32,   sf::Color(246, 124, 95)},
		{64,   sf::Color(246, 94, 59)},
		{128,  sf::Color(237, 207, 114)},
		{256,  sf::Color(237, 204, 97)},
		{512,  sf::Color(237, 200, 80)},
		{1024, sf::Color(237, 197, 63)},
		{2048, sf::Color(237, 194, 46)},
		{4096, sf::Color(237, 190, 30)},
		{8192, sf::Color(237, 187, 0)},
		{16384,sf::Color(237, 183, 0)},
		{32768,sf::Color(237, 180, 0)},
		{65536,sf::Color(237, 176, 0)},
		{131072,sf::Color(237, 173, 0)}
	};
}

sf::Color TileColors::getColor(int value)
{
	if (colorMap.find(value) != colorMap.end()) //Busca a chave value no mapa e o retorna. Retorna colorMap.end() se a chave não existir
		return colorMap[value];
	return sf::Color::Black; // preto setado como padrão
};

void RenderTile::draw(sf::RenderWindow& window)
{
    window.draw(tile);
    if (value != 0) // Só desenha texto se não for vazio
        window.draw(tileText);
}

RenderTile::RenderTile(Board &board, TileColors colors, const sf::Font &font, int x, int y)
: board(board), colors(colors), font(font), x(x), y(y)
{
    float margin_value = 10.f;
    float tile_size = 100.f;

    this->value = board.grid_at(x, y).get_value();

    // Posição do visor de pontuação (altura do visor)
    float score_panel_height = 100.f;

    // Calcular a posição Y considerando o visor de pontuação
    float positionY = score_panel_height + y * (tile_size + margin_value);

    // Calcular a posição X para centralizar os tiles horizontalmente
    float window_width = 500.f;
    float total_tiles_width = 4 * tile_size + 3 * margin_value; // 4 tiles + 3 margens
    float positionX = (window_width - total_tiles_width) / 2.0f + x * (tile_size + margin_value);

    // Configurar o tamanho do tile
    tile.setSize(sf::Vector2f(tile_size, tile_size));
    tile.setPosition(positionX, positionY);

    // Cor do tile e estilização
    tile.setFillColor(colors.getColor(value));
    tile.setOutlineThickness(2.f);
    tile.setOutlineColor(sf::Color(150, 150, 150));

    // Configuração do texto
    tileText.setFont(font);
    tileText.setCharacterSize(24);
    tileText.setString(std::to_string(value));
    tileText.setFillColor(sf::Color::White);

    update();
}

void RenderTile::update()
{
	int value = board.grid_at(x, y).get_value();

	tile.setFillColor(colors.getColor(value));

	if (value == 0)
		tileText.setString("");
	else
		tileText.setString(std::to_string(value));

	sf::FloatRect textBounds = tileText.getLocalBounds();
	tileText.setOrigin(textBounds.left + textBounds.width / 2.0f,
	                   textBounds.top + textBounds.height / 2.0f);

	tileText.setPosition(tile.getPosition().x + tile.getSize().x / 2,
	                     tile.getPosition().y + tile.getSize().y / 2);
}

