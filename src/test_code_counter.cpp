// Copyright Alex Siqueira
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

TEST(CodeLineCounting, OnlyComments) {
    std::string negative_1("code/*comment*/");
    std::string negative_2("/*comment*/code");
    std::string positive_1("// comment only");
    std::string positive_2("/*comment/comment");

    EXPECT_EQ(false, only_comments(negative_1));
    EXPECT_EQ(false, only_comments(negative_2));
    EXPECT_EQ(true, only_comments(positive_1));
    EXPECT_EQ(true, only_comments(positive_2));
}

TEST(CodeLineCounting, EndsComment) {
    std::string positive_1("code/*comment*/");
    std::string positive_2("//comment");
    std::string negative_1("/*comment only");
    std::string negative_2("/*comment/comment");

    EXPECT_EQ(true, ends_comment(positive_1));
    EXPECT_EQ(true, ends_comment(positive_2));
    EXPECT_EQ(false, ends_comment(negative_1));
    EXPECT_EQ(false, ends_comment(negative_2));
}

TEST(CodeLineCounting, InitiatesComment) {
    std::string positive_1("code/*comment*/");
    std::string positive_2("//comment");
    std::string negative_1("comment only*/");
    std::string negative_2("only code");

    EXPECT_EQ(true, initiates_comment(positive_1));
    EXPECT_EQ(true, initiates_comment(positive_2));
    EXPECT_EQ(false, initiates_comment(negative_1));
    EXPECT_EQ(false, initiates_comment(negative_2));
}

TEST(CodeLineCounting, NextLineIsComment) {
    std::string positive_1("code/*comment");
    std::string positive_2("/*comment");
    std::string positive_3("//comment\\");
    std::string negative_1("/*comment only*/");
    std::string negative_2("comment only*/");
    std::string negative_3("//only comment");
    std::string negative_4("only code");

    EXPECT_EQ(true, next_line_is_comment(positive_1));
    EXPECT_EQ(true, next_line_is_comment(positive_2));
    EXPECT_EQ(true, next_line_is_comment(positive_3));
    EXPECT_EQ(false, next_line_is_comment(negative_1));
    EXPECT_EQ(false, next_line_is_comment(negative_2));
    EXPECT_EQ(false, next_line_is_comment(negative_3));
    EXPECT_EQ(false, next_line_is_comment(negative_4));
}

TEST(CodeLineCounting, CodeLines) {
    std::string code_01("//comment\\");
    std::string code_02("//comment\\\nanothercomment*/\n");
    std::string code_1("code\n/*comment*/");
    std::string code_2(" \ncode\ncode\n/*comment");
    std::string code_3(" \ncode\ncode\n/*comment\n*/code\n");

    EXPECT_EQ(0, count_code_lines(code_01));
    EXPECT_EQ(0, count_code_lines(code_02));
    EXPECT_EQ(1, count_code_lines(code_1));
    EXPECT_EQ(2, count_code_lines(code_2));
    EXPECT_EQ(3, count_code_lines(code_3));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
