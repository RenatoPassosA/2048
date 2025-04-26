#include "render_board.hpp"

void RenderBoard::game_loop()
{
	while (window.isOpen())
    {
        // Verificar todos os eventos da janela que ocorreram desde a última iteração
        while (window.pollEvent(event))
        {
            // Evento de "fechar" a janela: fechamos a janela
            if (event.type == sf::Event::Closed)
                window.close();
        }
		window.clear(sf::Color(250, 248, 239)); // Cor de fundo do 2048
		for (RenderTile &tile : tiles_renderizados)
			tile.draw(window);
        
		window.display();
    }
}

RenderBoard::RenderBoard(Board &board)
{
	//criaçaõ da janela
	window.create(sf::VideoMode(500, 600), "2048", sf::Style::Default);

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