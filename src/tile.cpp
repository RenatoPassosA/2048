#include "tile.hpp"

Tile::Tile() {
	valor = 0;
	x = 0;
	y = 0;
}

Tile::Tile(int pos_x, int pos_y)
{
	valor = 0;
	x = pos_x;
	y = pos_y;
};

void Tile::mostrar()
{
	std::cout 	<< "Valor: " << valor << std::endl
				<< "X: " << x << std::endl
				<< "Y: " << y << std::endl;
}

int	Tile::get_x() const
{
	return (this->x);
}

int	Tile::get_y() const
{
	return (this->y);
}

int	Tile::get_value() const 
{
	return (this->valor);
}

void	Tile::set_value(int value)
{
	valor = value;
}

void	Tile::set_x(int pos_x)
{
	x = pos_x;
}

void	Tile::set_y(int pos_y)
{
	y = pos_y;
}