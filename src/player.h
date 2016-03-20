#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <list>
#include "player_board.h"
#include "resources.h"
#include "action.h"

class Player
{
public:
    PlayerBoard player_board;
    ResourceCollection resources = {0};

    Action* select_move(std::list<Action*> available_actions);
    int victory_points();
};

#endif
