#ifndef BOARD_STATE_HPP
#define BOARD_STATE_HPP

#include <array>

struct BoardState
{
    std::array<std::array<int, 4>, 4> grid;
    int score;

    BoardState();
};

#endif