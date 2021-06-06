//  Copyright 2021 MalininDmitry
#include "../include/task1.h"
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <iostream>

TEST(LAB9, TEST1) {
    std::vector<std::string> arr5 = {"a", "ccc",
        "dd", "asdasd"};
    std::function<bool(std::string, std::string)>
    comp5 =[](std::string a, std::string b){return
        a.length()%3 >b.length()%3;};
    sorttask(arr5, comp5);
    std::vector<std::string> answer = { "ccc",
        "asdasd", "a", "dd"};
    EXPECT_EQ(answer, arr);
}

TEST(LAB9, TEST2) {
    std::vector<std::string> arr6 = {"a", "ccc",
        "dd", "asdasd"};
    std::function<bool(std::string, std::string)>
    comp6 =[](std::string a, std::string b){return
        a[0] < b[0];};
    sorttask(arr6, comp6);
    std::vector<std::string> answer = {"dd", "ccc",
        "a", "asdasd" };
    EXPECT_EQ(answer, arr);
}

TEST(LAB9, TEST3) {
    std::vector<std::string> arr4 = {"a", "ccc",
        "dd", "asdasd"};
    std::function<bool(std::string, std::string)>
    comp4 =[](std::string a, std::string b){return
        a.length()>b.length();};
    sorttask(arr4, comp4);
    std::vector<std::string> answer = { "a", "dd",
        "ccc", "asdasd"};
    EXPECT_EQ(answer, arr2);
}


TEST(LAB9, TEST4) {
    std::vector<std::string> arr3 = {"aaa", "ccc", "ddd"};
    std::function<bool(std::string, std::string)>
    comp3 =[](std::string a, std::string b)
    {return a>b;};
    sorttask(arr3, comp3);
    std::vector<std::string> answer = { "aaa",
        "ccc", "ddd" };
    EXPECT_EQ(answer, arr2);
}
