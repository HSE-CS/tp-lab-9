// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "task1.h"
#include "task2.h"
#include "task3.h"


TEST(task1, t_1) {
 std::vector<std::string> vector_elements = {"scapigerous",
  "distraint", "wheeled"};
    bubbleSort(vec, [](std::string& s1, std::string& s2) {
        return s1 < s2; });
    std::vector<std::string> expect =
    { "distraint", "scapigerous", "wheeled"};
    EXPECT_EQ(expect, vec);
}

TEST(task1, t_2) {
    std::vector<std::string> vec = {"scapigerous", "distraint", "wheeled"};
    bubbleSort(vec, [](std::string& s1, std::string& s2) {
    return s1.size() < s2.size(); });
    std::vector<std::string> expect =
    {"wheeled", "distraint", "scapigerous"};
    EXPECT_EQ(expect, vec);
}

TEST(task1, t_3) {
    std::vector<std::string> vec = {"scapigerous", "distraint", "wheeled"};
    bubbleSort(vec, [](std::string& s1, std::string& s2) {
    return s1.back() < s2.back(); });
    std::vector<std::string> expect =
    {"wheeled", "scapigerous", "distraint"};
    EXPECT_EQ(expect, vec);
}

TEST(task1, t_4) {
    std::vector<std::string> vec = {"scapigerous", "distraint", "wheeled"};
  bubbleSort(vec, [](std::string& s1, std::string& s2) {
    return s1[0] < s2[0]; });
    std::vector<std::string> expect =
    { "distraint", "scapigerous", "wheeled"};
    EXPECT_EQ(expect, vec);
}
