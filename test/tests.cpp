// Copyright 2021 Nikita Naumov
#include <gtest/gtest.h>
#include "../include/task1.h"
#include "../include/task2.h"
#include "../include/task3.h"

TEST(bubble_sort_test, test1) {
    std::vector<std::string> testVector,
                            idealVector;
    testVector.push_back("a");
    testVector.push_back("aaaa");
    testVector.push_back("aaa");
    testVector.push_back("aa");

    idealVector.push_back("a");
    idealVector.push_back("aa");
    idealVector.push_back("aaa");
    idealVector.push_back("aaaa");

    auto comp1 = [](std::string str1, std::string str2)->bool{
        return (str1.length() > str2.length() ? true : false);
    };
    stringBubbleSort(testVector, comp1);
    bool test = true;
    for (size_t i = 0; i < idealVector.size(); ++i) {
        if (testVector[i] != idealVector[i]) {
            test = false;
        }
    }
    EXPECT_EQ(test, true);
}

TEST(bubble_sort_test, test2) {
    std::vector<std::string> testVector,
                            idealVector;
    testVector.push_back("a");
    testVector.push_back("aaaa");
    testVector.push_back("aaa");
    testVector.push_back("aa");

    idealVector.push_back("aaaa");
    idealVector.push_back("aaa");
    idealVector.push_back("aa");
    idealVector.push_back("a");

    auto comp1 = [](std::string str1, std::string str2)->bool{
        return (str1.length() < str2.length() ? true : false);
    };
    stringBubbleSort(testVector, comp1);
    bool test = true;
    for (size_t i = 0; i < idealVector.size(); ++i) {
        if (testVector[i] != idealVector[i]) {
            test = false;
        }
    }
    EXPECT_EQ(test, true);
}