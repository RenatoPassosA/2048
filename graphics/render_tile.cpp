#include "render_tile.hpp"

/*
Classe render tile:
	representar visualmente cada tile lógico.
	ter acesso aos atributos do tile lógigo.
	ser capaz de atualizar o visual conforme o decorrer do jogo.
*/

RenderTile::RenderTile(Tile &tile, TileColors &colors, sf::Font &font)
	: tile_ref(tile), font_ref(font), color_ref(colors)
{
	
	int tile_size = 100;
	int margin = 10;
	int panel_score_height = 100;
	int window_width = 500;

	int board_width = (tile_size * 4) + (margin * 3);
	int	out_margin = (window_width - board_width) / 2;

	int pos_x = out_margin + tile.get_y() * (tile_size + margin);
	int pos_y = panel_score_height + tile.get_x() * (tile_size + margin);
	
	tile_shape.setSize(sf::Vector2f(tile_size, tile_size));
    tile_shape.setPosition(pos_x, pos_y);
    tile_shape.setOutlineThickness(2.f);
    tile_shape.setOutlineColor(sf::Color(150, 150, 150));

    tile_text.setFont(font);
    tile_text.setCharacterSize(24);
    tile_text.setFillColor(sf::Color::White);

	update_visual();
}

void RenderTile::update_visual()
{
    int value = tile_ref.get_value();

	//std::cout << "Value:" << value << std::endl;
 
    tile_shape.setFillColor(color_ref.getColor(value));
    tile_text.setString(std::to_string(value));
	if (value == 0)
		tile_text.setString("");

    sf::FloatRect textBounds = tile_text.getLocalBounds();
    tile_text.setOrigin(textBounds.left + textBounds.width / 2.f, textBounds.top + textBounds.height / 2.f);
    tile_text.setPosition(tile_shape.getPosition().x + tile_shape.getSize().x / 2.f,
                          tile_shape.getPosition().y + tile_shape.getSize().y / 2.f);
}

void RenderTile::draw(sf::RenderWindow& window)
{
    window.draw(tile_shape);
    window.draw(tile_text);
}