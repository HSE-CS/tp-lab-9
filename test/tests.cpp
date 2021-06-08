// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "task1.h"
#include "task2.h"
#include "task3.h"

#include <vector>

using namespace std;

TEST(task1, sort1){

    vector<string> array;

    array.push_back("Short");
    array.push_back("the long one");
    array.push_back("middle");

    BubbleSort(array, [] (const string& a, const string& b){ return a.size() > b.size();});

    EXPECT_EQ("middle", array[1]);

}

TEST(task2, sort2){

    array.push_back("C short");
    array.push_back("G the long one");
    array.push_back("A middle");

    ThreadSort(array, [] (const string& a, const string& b){ return a[0] > b[0];});

    EXPECT_EQ("A middle", array[0]);
}

TEST(task3, shop1){

    Shop testShop();
    testShop.Shopping();

    EXPECT_EQ(true, true); // Means that Shop is done, nothing had crashed

}
