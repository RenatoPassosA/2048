#ifndef RENDERER_HPP
# define RENDERER_HPP

#include "../src/board.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <unordered_map>

class RenderTile{
	private:
		sf::RectangleShape		tile_shape; 
		sf::Text				tile_text;
		Tile					&tile_ref;
		sf::Font				&font_ref;
		TileColors				&color_ref;
		
	public:
		RenderTile(Tile &tile, TileColors &colors, sf::Font &font);
		void	draw(sf::RenderWindow& window);
		void	update_visual();
};

#endif