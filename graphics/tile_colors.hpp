#ifndef TILE_COLORS_HPP
# define TILE_COLORS_HPP

#include <SFML/Graphics.hpp>
#include <unordered_map>

class TileColors {
	private:
		std::unordered_map<int, sf::Color>	colorMap; //unordered_map é a mesma coisa que o dict
	
	public:
		TileColors();
		sf::Color	getColor(int value);
};

#endif