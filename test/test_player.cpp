#include "gtest/gtest.h"
#include "src/player.h"
#include "src/player_board.h"
#include "src/action.h"
#include "src/board_space.h"
#include "src/board.h"

class PlayerTest : public ::testing::Test {
protected:
    // Player object to test
    Player p1;

    // Board with a single space/action
    Board b1;
    BoardSpace bs1;

    virtual void SetUp() {
        b1.board_spaces.push_back(&bs1);
    }

    // virtual void TearDown() {}
};

// Test initial victory points
TEST_F(PlayerTest, InitialVPTest) {
    EXPECT_EQ(-20, p1.victory_points());
}

// Test victory points can change
TEST_F(PlayerTest, ChangeVPTest) {
    int expected_vps = -20;

    // Grain from -1 to +1
    p1.resources.grain = 2;
    expected_vps += 2;
    EXPECT_EQ(expected_vps, p1.victory_points());

    // Cattle from -1 to +4
    p1.resources.cattle = 20;
    expected_vps += 5;
    EXPECT_EQ(expected_vps, p1.victory_points());
}

// Test Player returns the only available action
TEST_F(PlayerTest, BasicActionTest) {
    // Board with single action leaves no choice
    EXPECT_EQ(bs1.action, p1.select_move(b1.available_actions(p1)));
}
