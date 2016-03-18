#include "gtest/gtest.h"

// Arbitrary passing test
TEST(ExampleTest, PassingTest) {
  EXPECT_EQ(0, 1 - 1);
}

// Arbitrary failing test
TEST(ExampleTest, FailingTest) {
  EXPECT_EQ(0, 1);
}