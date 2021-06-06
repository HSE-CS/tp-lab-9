// Copyright 2021 VA
#include "pch.h"
#include "gtest/gtest.h"
#include "task1.h"
#include "task2.h"
#include "textgen.h"
#include <iterator>
#include <algorithm>
#include <fstream>

TEST(TestTask1, Test1) {
    std::vector<std::string> arr = { "gggg", "aaaa", "lllll", "bbbbbb", "pppppppp", "dddddd" };
    std::function<bool(std::string, std::string)>  comp = [](std::string a, std::string b) { return a > b; };
    Sort(arr, comp);
    std::vector<std::string> expect = { "aaaa", "bbbbbb" , "dddddd", "gggg", "lllll", "pppppppp" };
    EXPECT_EQ(expect, arr);
}

TEST(TestTask1, Test2) {
    std::vector<std::string> arr = { "gggg", "aaa", "l", "bbbbbb", "pp", "dddddddddddd" };
    std::function<bool(std::string, std::string)>  comp = [](std::string a, std::string b) { return a.length() > b.length(); };
    Sort(arr, comp);
    std::vector<std::string> expect = { "l", "pp" , "aaa", "gggg", "bbbbbb", "dddddddddddd" };
    EXPECT_EQ(expect, arr);
}

TEST(TestTask1, Test3) {
    std::vector<std::string> arr = { "yyyaads", "ffaaa", "friend", "ppaad", "rasss", "ddd" };
    std::function<bool(std::string, std::string)>  comp = [](std::string a, std::string b) { return a[1] > b[1]; };
    Sort(arr, comp);
    std::vector<std::string> expect = { "rasss", "ddd" , "ffaaa", "ppaad", "friend",  "yyyaads" };
    EXPECT_EQ(expect, arr);
}

TEST(TestTask1, Test4) {
    std::vector<std::string> arr = { "yyyaads", "ffaaa", "friend", "ppaad", "rasss", "ddd" };
    std::function<bool(std::string, std::string)>  comp = [](std::string a, std::string b) { return a < b; };
    Sort(arr, comp);
    std::vector<std::string> expect = { "yyyaads", "rasss" , "ppaad", "friend", "ffaaa",  "ddd" };
    EXPECT_EQ(expect, arr);
}

TEST(TEstTask1, Test5) {
    std::vector<std::string> arr = { "yyyaads", "ffaaa", "frieng", "ppaad", "dddb" };
    std::function<bool(std::string, std::string)>  comp = [](std::string a, std::string b) { return a[a.length() - 1] > b[b.length() - 1]; };
    Sort(arr, comp);
    std::vector<std::string> expect = { "ffaaa", "dddb" , "ppaad", "frieng", "yyyaads" };
    EXPECT_EQ(expect, arr);
}

TEST(TestTask2, Test6) {
    std::vector<std::string> arr = { "gggg", "aaaa", "lllll", "bbbbbb", "pppppppp", "dddddd" };
    std::function<bool(std::string, std::string)>  comp = [](std::string a, std::string b) { return a > b; };
    std::thread th1(Sort2, arr, comp);
    std::thread th2(Sort2, arr, comp);
    std::thread th3(Sort2, arr, comp);
    th1.join();
    th2.join();
    th3.join();
    std::vector<std::string> expect = { "aaaa", "bbbbbb" , "dddddd", "gggg", "lllll", "pppppppp" };
    EXPECT_EQ(expect, arr);
}
