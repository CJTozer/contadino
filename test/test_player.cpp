#include "gtest/gtest.h"
#include "src/player.h"

class PlayerTest : public ::testing::Test {
protected:
   // virtual void SetUp() {}

   // virtual void TearDown() {}

   Player p1;
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
