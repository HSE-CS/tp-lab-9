// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "task1.h"
#include "task2.h"
#include "task3.h"

#include <vector>

using namespace std;

TEST(task1, sort1){

    vector<string> strs;

    strs.push_back("Short");
    strs.push_back("the long one");
    strs.push_back("middle");

    BubbleSort(strs, [] (const string& a, const string& b){ return a.size() > b.size();});

    EXPECT_EQ("middle", array[1]);

}

TEST(task2, sort2){
    vector <string> strs;

    strs.push_back("C short");
    strs.push_back("G the long one");
    strs.push_back("A middle");

    ThreadSort(strs, [] (const string& a, const string& b){ return a[0] > b[0];});

    EXPECT_EQ("A middle", strs[0]);
}

TEST(task3, shop1){

    Shop testShop();
    testShop.Shopping();

    EXPECT_EQ(true, true); // Means that Shop is done, nothing had crashed

}
