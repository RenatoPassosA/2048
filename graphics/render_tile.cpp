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

RenderTile::RenderTile(Board &board, TileColors colors, const sf::Font &font, int x, int y) //inicialziar font no programa principal e enviar
{
	float	margin_value = 10.f;
	float	tile_size = 100.f;

	this->value = board.grid_at(x, y).get_value();

	//posição e tamanho:
	tile.setSize(sf::Vector2f(100.f, 100.f));
	tile.setPosition(x * (tile_size + margin_value) , y * (tile_size + margin_value));
	
	//cor do tile e estilização
	tile.setFillColor(colors.getColor(value));
	tile.setOutlineThickness(2.f);
	tile.setOutlineColor(sf::Color(150, 150, 150));
	
	//configuração do texto
	tileText.setFont(font);
	tileText.setCharacterSize(24);
	tileText.setString(std::to_string(value));
	tileText.setFillColor(sf::Color::White);
	
	if (value == 0)
		tileText.setString("");

	// Ajusta a origem para o centro do texto
	sf::FloatRect textBounds = tileText.getLocalBounds();
	tileText.setOrigin(textBounds.left + textBounds.width/2.0f, textBounds.top + textBounds.height/2.0f);

	// Posiciona no centro do tile
	tileText.setPosition(tile.getPosition().x + tile.getSize().x/2,
    tile.getPosition().y + tile.getSize().y/2);
};
