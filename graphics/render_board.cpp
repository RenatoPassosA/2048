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

void RenderBoard::draw_all(sf::RenderWindow	&window_ref)
{
	for (RenderTile &tile : get_tiles())
		tile.draw(window_ref);
};

void RenderBoard::update_all_tiles()
{
	for (auto &tile: tiles_renderizados)
		tile.update_visual();
};

RenderBoard::RenderBoard(Board &board)
	: board_ref(board)/*, window_ref(window)*/
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
