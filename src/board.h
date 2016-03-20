#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <list>
#include "player.h"
#include "action.h"
#include "board_space.h"

class Board
{
public:
    std::list<Action> available_actions(Player p);
    int round = 1;
    std::list<BoardSpace> board_spaces;

};

#endif
