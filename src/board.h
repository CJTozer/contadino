#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <list>
#include "player.h"
#include "action.h"

class Board
{
public:
    std::list<Action> available_actions(Player p);
};

#endif
