// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "../include/task1.h"
#include "../include/task2.h"
#include "../include/task3.h"

// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>

std::function<bool(std::string, std::string)> comp_f = [](std::string a,
    std::string b) {
    return a > b;
};

std::function<bool(std::string, std::string)> comp_s = [](std::string a,
    std::string b) {
    int count_a = 0;
    int count_b = 0;
    for (int64_t i = 0; i < static_cast<int64_t>(a.size()); ++i)
        if (a[i] >= 'A' && a[i] <= 'Z')
            count_a++;
    for (int64_t i = 0; i < static_cast<int64_t>(b.size()); ++i)
        if (b[i] >= 'A' && b[i] <= 'Z')
            count_b++;
    if (count_a < count_b) {
        return true;
    } else {
        return false;
    }
};

std::function<bool(std::string, std::string)> comp_th = [](std::string a,
    std::string b) {
    int count_a = 0;
    int count_b = 0;
    for (int64_t i = 0; i < static_cast<int64_t>(a.size()); ++i)
        if (a[i] == 'a' || a[i] == 'A')
            count_a++;
    for (int64_t i = 0; i < static_cast<int64_t>(b.size()); ++i)
        if (b[i] == 'a' || b[i] == 'A')
            count_b++;
    if (count_a < count_b) {
        return true;
    } else {
        return false;
    }
};

TEST(task1, t_1) {
    std::vector<std::string> test_vect = {"Testus", "Class", "hello_world" };
    bubbleSort(test_vect, comp_f);
    std::vector<std::string> expect = {"Class", "Testus", "hello_world" };
    EXPECT_EQ(expect, test_vect);
}

TEST(task1, t_2) {
    std::vector<std::string> test_vect = { "Testus", "CLASS", "hello_world" };
    bubbleSort(test_vect, comp_s);
    std::vector<std::string> expect = {"CLASS", "Testus", "hello_world" };
    EXPECT_EQ(expect, test_vect);
}

TEST(task1, t_3) {
    std::vector<std::string> test_vect = {"just String", "Kalivan",
        "Azaza", "babaBoi" };
    bubbleSort(test_vect, comp_th);
    std::vector<std::string> expect = { "Azaza", "Kalivan",
        "babaBoi", "just String"};
    EXPECT_EQ(expect, test_vect);
}

