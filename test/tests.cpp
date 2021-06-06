//Copyright 2021 Kris


#include <gtest/gtest.h>
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "main1.cpp"
#include "main2.cpp"
#include "main3.cpp"
#include <iostream>
#include <vector>
#include <string>


TEST(Sort, TEST1) {
    std::vector<std::string> v = { "kris", "peper", "salt",
        "lion", "qwerty", "ytrewq" };
    v = bubblesort(v, comp_1);
    std::vector<std::string> answer = { "kris", "lion", "peper",
        "qwerty", "salt", "ytrewq" };
    EXPECT_EQ(answer, v);
}

TEST(Sort, TEST2) {
    std::vector<std::string> v = { "kris", "peper", "salt",
        "lion", "qwerty", "ytrewq" };
    v = bubblesort(v, comp_2);
    std::vector<std::string> answer = { "kris", "lion", "peper",
        "qwerty", "salt", "ytrewq" };
    EXPECT_EQ(answer, v);
}

TEST(Sort, TEST3) {
    std::vector<std::string> v = { "kris", "peper", "salt",
        "lion", "qwerty", "ytrewq" };
    v = bubblesort(v, comp_3);
    std::vector<std::string> answer = { "salt", "kris", "lion",
        "peper", "qwerty", "ytrewq"};
    EXPECT_EQ(answer, v);
}

TEST(Sort, TEST4) {
    std::vector<std::string> v = { "kris", "peper", "salt",
        "lion", "qwerty", "ytrewq" };
    v = bubblesort(v, comp_4);
    std::vector<std::string> answer = { "lion", "ytrewq",
        "peper", "kris", "salt", "qwerty"};
    EXPECT_EQ(answer, v);
}

TEST(Sort, TEST5) {
    std::vector<std::string> v = { "kris", "peper", "salt",
        "lion", "qwerty", "ytrewq" };
    v = bubblesort(v, comp_5);
    std::vector<std::string> answer = { "lion", "kris", "salt",
        "peper", "ytrewq", "qwerty"};
    EXPECT_EQ(answer, v);
}
