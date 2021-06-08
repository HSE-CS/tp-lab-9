// Copyright 2021 FOM
#include <gtest/gtest.h>
#include "task1.h"
#include "task2.h"
#include "task3.h"

TEST(test, test_1) {
    std::vector<std::string> test_1 = { "monday", "sunday",
                                            "saturday", "friday" ,
        "wednesday" , "thursday", "tuesday" };
    BubbleSortParrallel(test_1, [](const std::string& first_,
        const std::string& second_) {
        return first_.length() > second_.length(); });
    std::vector answer = { "wednesday",
        "saturday", "thursday", "tuesday", "monday", "sunday", "friday" };
    EXPECT_EQ(answer, test_1);
}

TEST(test, test_2) {
    std::vector<std::string> test_2 = { "classicism",
        "discreet", "nigella", "short", "term", "vehemence" };
    BubbleSortParrallel(test_2, [](const std::string& first_,
        const std::string& second_) {
        return first_.length() > second_.length(); });
    std::vector answer = { "classicism",
        "vehemence", "discreet", "nigella", "short", "term" };
    EXPECT_EQ(answer, test_2);
}

TEST(test, test_3) {
    std::vector<std::string> test_3 = { "arsenic",
        "kolovrate", "pre-depres", "precede", "radiology" };
    BubbleSortParrallel(test_3, [](const std::string& first_,
        const std::string& second_) {
        return first_.length() > second_.length(); });
    std::vector answer = { "pre-depres",
        "kolovrate", "radiology", "arsenic", "precede" };
    EXPECT_EQ(answer, test_3);
}

TEST(test, test_4) {
    std::vector<std::string> test_4 = { "bass",
        "homemaker", "lack", "of", "nervous", "voguls" };
    BubbleSortParrallel(test_4, [](const std::string& first_,
        const std::string& second_) {
        return first_.length() > second_.length(); });
    std::vector answer = { "homemaker",
        "nervous", "voguls", "bass", "lack", "of" };
    EXPECT_EQ(answer, test_4);
}

TEST(test, test_5) {
    std::vector<std::string> test_5 = { "cornice",
        "duchy", "ediuate", "haze", "pony" };
    BubbleSortParrallel(test_5, [](const std::string& first_,
        const std::string& second_) {
        return first_.length() > second_.length(); });
    std::vector answer = {"cornice",
        "ediuate", "duchy", "haze", "pony" };
    EXPECT_EQ(answer, test_5);
}
