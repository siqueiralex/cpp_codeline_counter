#include <gtest/gtest.h>
#include "../include/codeline_counter.hpp"

TEST(CodeLineCounting, OnlySpaces) {

    std::string spaces("   ");
    std::string bordering_spaces(" test ");
    std::string ending_spaces("test  ");
    std::string beginning_spaces("  test");
    
    EXPECT_EQ(true, only_spaces(spaces));
    EXPECT_EQ(false, only_spaces(bordering_spaces));
    EXPECT_EQ(false, only_spaces(ending_spaces));
    EXPECT_EQ(false, only_spaces(beginning_spaces));
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}