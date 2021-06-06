//  Copyright 2021 MalininDmitry
#include "../include/task1.h"
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <iostream>

TEST(LAB9, TEST1) {
    std::vector<int> arr = {1, 5, 2 ,4 ,6 ,7, -4 };
    std::function<bool(int, int)> comp =[](int a, int b){return a>b;};
    sorttask(arr, comp);

    std::vector<std::string> answer = { -4,
        1, 2, 4, 5, 6, 7 };
    EXPECT_EQ(answer, arr);
}

TEST(LAB9, TEST2) {
    std::vector<int> arr = {5, 1};
    std::function<bool(int, int)> comp =[](int a, int b){return a>b;};
    sorttask(arr, comp);

    std::vector<std::string> answer = { 1, 5};
    EXPECT_EQ(answer, arr);
}

TEST(LAB9, TEST3) {
    std::vector<double> arr2 = {1.4, 5.2, 2.3 ,4.1 ,6.4 ,7.4, -4.4 };
    std::function<bool(double, double)> comp2 =[](double a, double b){return a>b;};
    sorttask(arr2, comp2);

    std::vector<std::string> answer = { -4.4, 1.4, 2.3, 4.1, 5.2, 6.4, 7.4};
    EXPECT_EQ(answer, arr2);
}


TEST(LAB9, TEST4) {
    std::vector<std::string> arr3 = {"aaa", "ccc", "ddd"};
    std::function<bool(std::string, std::string)> comp3 =[](std::string a, std::string b){return a>b;};
    sorttask(arr3, comp3);

    std::vector<std::string> answer = { "aaa", "ccc", "ddd" };
    EXPECT_EQ(answer, arr2);
}
