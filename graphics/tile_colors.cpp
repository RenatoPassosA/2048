/*
essa classe é responsável por definir a cor de cada tile conforme o valor dele*/

#include "tile_colors.hpp"

TileColors::TileColors()
{
	colorMap = {
		{0,     sf::Color(205, 193, 180)},
		{2,     sf::Color(238, 228, 218)},
		{4,     sf::Color(237, 224, 200)},
		{8,     sf::Color(242, 177, 121)},
		{16,    sf::Color(245, 149, 99)},
		{32,    sf::Color(246, 124, 95)},
		{64,    sf::Color(246, 94, 59)},
		{128,   sf::Color(237, 207, 114)},
		{256,   sf::Color(237, 204, 97)},
		{512,   sf::Color(237, 200, 80)},
		{1024,  sf::Color(237, 197, 63)},
		{2048,  sf::Color(237, 194, 46)},
		{4096,  sf::Color(230, 170, 40)},
		{8192,  sf::Color(220, 140, 30)},
		{16384, sf::Color(200, 110, 20)},
		{32768, sf::Color(180, 90, 10)},
		{65536, sf::Color(160, 70, 5)},
		{131072,sf::Color(130, 50, 0)}
	};
}

sf::Color TileColors::getColor(int value)
{
	if (colorMap.find(value) != colorMap.end()) //Busca a chave value no mapa e o retorna. Retorna colorMap.end() se a chave não existir
		return colorMap[value];
	return sf::Color::Black; // preto setado como padrão
};