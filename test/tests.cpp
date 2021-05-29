//  Copyright Baklanov 2021
#include "../include/task1.h"
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <iostream>

TEST(Sort, TEST1) {
    std::vector<std::string> products = { "milk",
        "orange", "bread", "meat", "fish" };
    bubblesort(products, [](std::string a, std::string b)
        {return a.length() > b.length(); });
    std::vector<std::string> answer = { "milk",
        "meat", "fish", "bread", "orange" };
    EXPECT_EQ(answer, v);
}

TEST(Sort, TEST2) {
    std::vector<std::string> products = { "milk",
        "orange", "bread", "meat", "fish" };
    bubblesort(products, [](std::string a, std::string b)
        {return a.length() < b.length(); });
    std::vector<std::string> answer = { "orange",
        "bread", "milk", "meat", "fish" };
    EXPECT_EQ(answer, v);
}

TEST(Sort, TEST3) {
    std::vector<std::string> products = { "milk",
        "orange", "bread", "meat", "fish" };
    bubblesort(products, [](std::string a, std::string b)
        {return a < b; });
    std::vector<std::string> answer = { "orange",
        "milk", "meat", "fish", "bread" };
    EXPECT_EQ(answer, v);
}

TEST(Sort, TEST4) {
    std::vector<std::string> products = { "milk",
        "orange", "bread", "meat", "fish" };
    bubblesort(products, [](std::string a, std::string b)
        {return a > b; });
    std::vector<std::string> answer = { "bread",
        "fish", "meat", "milk", "orange" };
    EXPECT_EQ(answer, v);
}

TEST(Sort, TEST5) {
    std::vector<std::string> products = { "milk",
        "orange", "bread", "meat", "fish" };
    bubblesort(products, [](std::string a, std::string b)
        {return a[0] < b[0]; });
    std::vector<std::string> answer = { "orange",
        "meat", "milk", "fish", "bread" };
    EXPECT_EQ(answer, v);
}