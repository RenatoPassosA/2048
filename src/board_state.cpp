/*
classe board_state:
responsável por salvar o estado do board para fins de armazenar no histórico pro botao desfazer
*/

#include "board_state.hpp"

BoardState::BoardState()
    : score(0)
{
    for (auto& row : grid)
        row.fill(0);
}