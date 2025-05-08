#include "board_state.hpp"

BoardState::BoardState()
    : score(0)
{
    for (auto& row : grid)
        row.fill(0);
}