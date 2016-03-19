#include "player.h"

Action Player::select_move(std::list<Action> available_actions) {
    Action null_action({0}, {0});
    return null_action;
}

int Player::victory_points() {
    int vps = 0;

    // Fields: 0-1 | 2 | 3 | 4 | 5+
    // Points:  -1 | 1 | 2 | 3 | 4
    int fields = player_board.num_fields();
    if (fields < 1) {
        vps -= 1;
    } else if (fields <= 5) {
        vps += fields - 1;
    } else {
        vps += 4;
    }

    // Pastures:  0 | 1 | 2 | 3 | 4+
    // Points:   -1 | 1 | 2 | 3 | 4
    int pastures = player_board.num_pastures();
    if (pastures == 0) {
        vps -= 1;
    } else if (pastures <= 4) {
        vps += pastures;
    } else {
        vps += 4;
    }

    // Grain:   0 | 1-3 | 4-5 | 6-7 | 8+
    // Points: -1 |  1  |  2  |  3  | 4
    int total_grain = player_board.num_planted_grain() + resources.grain;
    if (total_grain == 0) {
        vps -= 1;
    } else if (total_grain <= 3) {
        vps += 1;
    } else if (total_grain <= 5) {
        vps += 2;
    } else if (total_grain <= 7) {
        vps += 3;
    } else {
        vps += 4;
    }

    // Vegetables:   0 | 1 | 2 | 3 | 4+
    // Points:      -1 | 1 | 2 | 3 | 4
    int total_veg = player_board.num_planted_veg() + resources.vegetables;
    if (total_veg == 0) {
        vps -= 1;
    } else if (total_veg <= 4) {
        vps += total_veg;
    } else {
        vps += 4;
    }

    // Sheep:   0 | 1-3 | 4-5 | 6-7 | 8+
    // Points: -1 |  1  |  2  |  3  | 4
    if (resources.sheep == 0) {
        vps -= 1;
    } else if (resources.sheep <= 3) {
        vps += 1;
    } else if (resources.sheep <= 5) {
        vps += 2;
    } else if (resources.sheep <= 7) {
        vps += 3;
    } else {
        vps += 4;
    }

    // Boar:    0 | 1-2 | 3-4 | 5-6 | 7+
    // Points: -1 |  1  |  2  |  3  | 4
    if (resources.boar == 0) {
        vps -= 1;
    } else if (resources.boar <= 2) {
        vps += 1;
    } else if (resources.boar <= 4) {
        vps += 2;
    } else if (resources.boar <= 6) {
        vps += 3;
    } else {
        vps += 4;
    }

    // Cattle:  0 | 1 | 2-3 | 4-5 | 6+
    // Points: -1 | 1 |  2  |  3  | 4
    if (resources.cattle == 0) {
        vps -= 1;
    } else if (resources.cattle == 1) {
        vps += 1;
    } else if (resources.cattle <= 3) {
        vps += 2;
    } else if (resources.cattle <= 5) {
        vps += 3;
    } else {
        vps += 4;
    }

    // Empty squares -> -1 for each
    vps -= player_board.empty_tiles();

    // Fenced stable -> +1 for each
    vps += player_board.fenced_stables();

    // Clay room -> +1 for each
    vps += player_board.clay_rooms();

    // Stone room -> +2 for each
    vps += 2 * player_board.stone_rooms();

    return vps;
}
