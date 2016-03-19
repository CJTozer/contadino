#include "player_board.h"

#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

class Player
{
private:
    PlayerBoard _player_board;
    int _grain = 0;
    int _veg = 0;
    int _sheep = 0;
    int _boar = 0;
    int _cattle = 0;

public:
    // Player();
    // ~Player();
    int victory_points();

};

#endif
