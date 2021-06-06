// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "task1.h"


TEST(task1, t_1) {
    std::vector<std::string> test_vect = { "Aboba", "Shampoo", "Biba",
    "it", "is", "Final", "God Job", "9"};
    bubble_sort(test_vect, comp_1);
    std::vector<std::string> expect =
    { "9", "Aboba", "Biba", "Final", "God Job", "Shampoo", "is", "it" };
    EXPECT_EQ(expect, test_vect);
}

TEST(task1, t_2) {
    std::vector<std::string> test_vect = { "Aboba", "Shampoo", "Biba",
    "it", "is", "Final", "God Job", "9" };
    bubble_sort(test_vect, comp_2);
    std::vector<std::string> expect =
    { "Final", "God Job", "Aboba", "Shampoo", "Biba", "it", "is", "9" };
    EXPECT_EQ(expect, test_vect);
}

TEST(task1, t_3) {
    std::vector<std::string> test_vect = { "Aboba", "Shampoo", "Biba",
    "it", "is", "Final", "God Job", "9" };
    bubble_sort(test_vect, comp_3);
    std::vector<std::string> expect =
    { "Aboba", "Shampoo", "Biba", "Final", "it", "is", "God Job", "9" };
    EXPECT_EQ(expect, test_vect);
}

TEST(task1, t_4) {
    std::vector<std::string> test_vect = { "Aboba", "Shampoo", "Biba",
    "it", "is", "Final", "God Job", "9" };
    bubble_sort(test_vect, comp_4);
    std::vector<std::string> expect =
    { "9", "Aboba", "Biba", "God Job", "Final", "Shampoo", "is", "it" };
    EXPECT_EQ(expect, test_vect);
}

TEST(task1, t_5) {
    std::vector<std::string> test_vect = { "Aboba", "Shampoo", "Biba",
    "it", "is", "Final", "God Job", "9" };
    bubble_sort(test_vect, comp_5);
    std::vector<std::string> expect =
    { "9", "it", "is", "Biba", "Aboba", "Final", "Shampoo", "God Job" };
    EXPECT_EQ(expect, test_vect);
}

TEST(task1, t_6) {
    std::vector<std::string> test_vect = { "Aboba", "Shampoo", "Biba",
    "it", "is", "Final", "God Job", "9" };
    BubbleSort_T(test_vect, [](std::string& x, std::string& y) {
        return x.back() < y.back(); });
    std::vector<std::string> expect =
    { "9", "Aboba", "Biba", "God Job", "Final", "Shampoo", "is", "it" };
    EXPECT_EQ(expect, test_vect);
}
