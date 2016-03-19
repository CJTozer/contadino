#include "player_board.h"
#include "resources.h"

#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

class Player
{
public:
    PlayerBoard player_board;
    ResourceCollection resources = {0};
    int victory_points();
};

#endif
