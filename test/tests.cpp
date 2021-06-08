// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "task1.h"
#include "task2.h"
#include "task3.h"

TEST(lab9, test1) {
    std::vector<std::string> test_array = { "I", "love", "you",
        "a", "little" };

    std::function<bool(std::string, std::string)> comp1 =
        [](std::string x, std::string y) { return x < y; };

    test_array = bubbleSort(test_array, comp1);

    std::vector<std::string> expect = {
        "you", "love", "little", "a", "I" };
    EXPECT_EQ(expect, test_array);
}

TEST(lab9, test2) {
    std::vector<std::string> test_array = { "You're", "so", "*******",
        "precious", "when", "you", "smile" };

    std::function<bool(const std::string &, const std::string &)> comp2 =
        [](const std::string &x, const std::string &y) {
        return x.length() < y.length();
    };

    test_array = bubbleSort(test_array, comp2);

    std::vector<std::string> expect = {
        "precious", "*******", "You're", "smile", "when", "you", "so" };
    EXPECT_EQ(expect, test_array);
}

TEST(lab9, test3) {
    std::vector<std::string> test_array = { "I", "love", "you",
        "a", "little" };

    std::function<bool(std::string, std::string)> comp1 =
        [](std::string x, std::string y) { return x < y; };

    test_array = bubbleSortTwoThread(test_array, comp1);

    std::vector<std::string> expect = {
        "you", "love", "little", "a", "I" };
    EXPECT_EQ(expect, test_array);
}

TEST(lab9, test4) {
    std::vector<std::string> test_array = { "You're", "so", "*******",
        "precious", "when", "you", "smile" };

    std::function<bool(const std::string &, const std::string &)> comp2 =
        [](const std::string &x, const std::string &y) {
        return x.length() < y.length();
    };

    test_array = bubbleSortTwoThread(test_array, comp2);

    std::vector<std::string> expect = {
        "precious", "*******", "You're", "smile", "when", "you", "so" };
    EXPECT_EQ(expect, test_array);
}
