#ifndef PLAYERBOARD_H_INCLUDED
#define PLAYERBOARD_H_INCLUDED

class PlayerBoard
{
public:
    // PlayerBoard();
    // ~PlayerBoard();
    int num_fields();
    int num_pastures();
    int num_planted_grain();
    int num_planted_veg();
    int empty_tiles();
    int fenced_stables();
    int clay_rooms();
    int stone_rooms();
};

#endif
