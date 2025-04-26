#ifndef RENDERER_HPP
# define RENDERER_HPP

#include "../src/board.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <unordered_map>

class TileColors {
	private:
		std::unordered_map<int, sf::Color>	colorMap; //unordered_map é a mesma coisa que o dict
	
	public:
		TileColors();
		sf::Color	getColor(int value);
};

class RenderTile{
	private:
		int value;
		sf::RectangleShape tile;
		sf::Text tileText;
		
	public:
		RenderTile(Board &board, TileColors colors, const sf::Font &font, int x, int y);
		void draw(sf::RenderWindow& window);
		
};

#endif