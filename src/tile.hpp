#ifndef TILE_HPP
#define TILE_HPP

#include <iostream>

class Tile {
private:
	int valor;
	int x;
	int y;
	
public:
 //construtor - inicializa os atributos do objeto
	Tile(); //construtor padrão
	Tile(int x, int y); //construtor com argumentos

	/*nesse caso, estou fazer uma sobrecarga de construtor - o compilador escolher qual construtor usar com base nos argumentos passados*/
	
//método - funções que pertencem a uma classe e podem acessar ou modificar os atributos da classe -  ações ou comportamentos que um objeto pode executar
	void		mostrar(); //método - funções que pertencem a uma classe e podem acessar ou modificar os atributos da classe -  ações ou comportamentos que um objeto pode executar
	int			get_x() const;	
	int			get_y() const;
	int			get_value() const;
	void		set_value(int value);
	void		set_x(int x);
	void		set_y(int y);
	

};

#endif

/*
quando deu defino algo private eu estou dando uma segurança a mais.
eu posso, por ex, colocar uma validação para a alteração de um atributo.
*/