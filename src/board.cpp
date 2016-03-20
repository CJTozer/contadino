#include "board.h"

std::list<Action*> Board::available_actions(Player& p) {
    std::list<Action*> action_list;

    // Get available actions from all board spaces.
    for (std::list<BoardSpace*>::const_iterator iterator = board_spaces.begin();
         iterator != board_spaces.end();
         ++iterator) {
        action_list.push_back((*iterator)->action);
    }
    return action_list;
}
