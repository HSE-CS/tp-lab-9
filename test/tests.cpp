// Copyright 2021 S
#include <gtest/gtest.h>
#include <mutex>
#include <algorithm>
#include <thread>
#include "task1.h"
#include "task2.h"
#include "task3.h"

TEST(tests, test1) {
    std::vector<std::string> exampleStrings = { "c", "d", "a", "b" };

    std::function<bool(std::string, std::string)> comp_1 =
            [](std::string str1, std::string str2) {
            return str1[0] < str2[0]; };

    exampleStrings = bubbleSort(exampleStrings, comp_1);

    std::vector<std::string> expected = { "d", "c", "b", "a" };
    EXPECT_EQ(expected, exampleStrings);
}

TEST(tests, test2) {
    std::vector<std::string> exampleStrings = { "c", "d", "a", "b" };

    std::function<bool(std::string, std::string)> comp2 =
            [](std::string str1, std::string str2) {
        return str1.back() < str2.back(); };
    exampleStrings = bubbleSort(exampleStrings, comp2);
    std::vector<std::string> expected = { "d", "c", "b", "a" };
    EXPECT_EQ(expected, exampleStrings);
}

TEST(tests, test3) {
    std::vector<std::string> exampleStrings = { "cd", "a", "bdsa" };

    std::function<bool(std::string, std::string)> comp4 =
            [](std::string str1, std::string str2) {
            return str1.size() < str2.size(); };
    exampleStrings = bubbleSort(exampleStrings, comp4);
    std::vector<std::string> expected = { "bdsa", "cd", "a" };
    EXPECT_EQ(expected, exampleStrings);
}

TEST(tests, test4) {
    std::vector<std::string> exampleStrings = { "c", "d", "a", "b" };

    std::function<bool(std::string, std::string)> comp5 =
            [](std::string x, std::string y) { return x < y; };
    exampleStrings = bubbleSort(exampleStrings, comp5);
    std::vector<std::string> expected = { "d", "c", "b", "a" };
    EXPECT_EQ(expected, exampleStrings);
}
