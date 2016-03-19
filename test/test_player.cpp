#include "gtest/gtest.h"
#include "src/player.h"

class PlayerTest : public ::testing::Test {
protected:
   // virtual void SetUp() {}

   // virtual void TearDown() {}

   Player p1;
};

// Arbitrary passing test
TEST_F(PlayerTest, InitialVPTest) {
  EXPECT_EQ(-20, p1.victory_points());
}
