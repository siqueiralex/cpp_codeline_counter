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

TEST(CodeLineCounting, EliminateSpaces) {
    std::string spaces("   ");
    std::string spaces_nl("   \n");
    std::string bordering_spaces(" test ");
    std::string ending_spaces("test  ");
    std::string beginning_spaces("  test");

    elim_spaces(&spaces);
    elim_spaces(&spaces_nl);
    elim_spaces(&bordering_spaces);
    elim_spaces(&ending_spaces);
    elim_spaces(&beginning_spaces);

    EXPECT_STREQ("", spaces.c_str());
    EXPECT_STREQ("\n", spaces_nl.c_str());
    EXPECT_STREQ("test", bordering_spaces.c_str());
    EXPECT_STREQ("test", ending_spaces.c_str());
    EXPECT_STREQ("test", beginning_spaces.c_str());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}