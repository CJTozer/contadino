#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "board.h"

class Game {
public:
    Board board;

    Game(Board& board): board(board) {}
};

#endif
