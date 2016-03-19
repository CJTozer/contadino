#include "player.h"

int Player::victory_points() {
    int vps = 0;

    // Fields: 0-1 | 2 | 3 | 4 | 5+
    // Points:  -1 | 1 | 2 | 3 | 4
    int fields = _player_board.num_fields();
    if (fields < 1) {
        vps -= 1;
    } else if (fields <= 5) {
        vps += fields - 1;
    } else {
        vps += 4;
    }

    // Pastures:  0 | 1 | 2 | 3 | 4+
    // Points:   -1 | 1 | 2 | 3 | 4
    int pastures = _player_board.num_pastures();
    if (pastures == 0) {
        vps -= 1;
    } else if (pastures <= 4) {
        vps += pastures;
    } else {
        vps += 4;
    }

    // Grain:   0 | 1-3 | 4-5 | 6-7 | 8+
    // Points: -1 |  1  |  2  |  3  | 4
    int grain = _player_board.num_planted_grain() + _grain;
    if (grain == 0) {
        vps -= 1;
    } else if (grain <= 3) {
        vps += 1;
    } else if (grain <= 5) {
        vps += 2;
    } else if (grain <= 7) {
        vps += 3;
    } else {
        vps += 4;
    }

    // Vegetables:   0 | 1 | 2 | 3 | 4+
    // Points:      -1 | 1 | 2 | 3 | 4
    int veg = _player_board.num_planted_veg() + _veg;
    if (veg == 0) {
        vps -= 1;
    } else if (veg <= 4) {
        vps += veg;
    } else {
        vps += 4;
    }

    // Sheep:   0 | 1-3 | 4-5 | 6-7 | 8+
    // Points: -1 |  1  |  2  |  3  | 4
    if (_sheep == 0) {
        vps -= 1;
    } else if (_sheep <= 3) {
        vps += 1;
    } else if (_sheep <= 5) {
        vps += 2;
    } else if (_sheep <= 7) {
        vps += 3;
    } else {
        vps += 4;
    }

    // Boar:    0 | 1-2 | 3-4 | 5-6 | 7+
    // Points: -1 |  1  |  2  |  3  | 4
    if (_boar == 0) {
        vps -= 1;
    } else if (_boar <= 2) {
        vps += 1;
    } else if (_boar <= 4) {
        vps += 2;
    } else if (_boar <= 6) {
        vps += 3;
    } else {
        vps += 4;
    }

    // Cattle:  0 | 1 | 2-3 | 4-5 | 6+
    // Points: -1 | 1 |  2  |  3  | 4
    if (_cattle == 0) {
        vps -= 1;
    } else if (_cattle == 1) {
        vps += 1;
    } else if (_cattle <= 3) {
        vps += 2;
    } else if (_cattle <= 5) {
        vps += 3;
    } else {
        vps += 4;
    }

    // Empty squares -> -1 for each
    vps -= _player_board.empty_tiles();

    // Fenced stable -> +1 for each
    vps += _player_board.fenced_stables();

    // Clay room -> +1 for each
    vps += _player_board.clay_rooms();

    // Stone room -> +2 for each
    vps += 2 * _player_board.stone_rooms();

    return vps;
}
