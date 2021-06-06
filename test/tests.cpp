// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "task1.h"
#include "task2.h"
#include "task3.h"

TEST(task1, test1) {
int arr_int[] = {1, 6, 10, 64, 7, 5, 8, 1, 7, 15, 18, 20, 26};
int arr_int1[] = {1, 1, 5, 6, 7, 7, 8, 10, 15, 18, 20, 26, 64};
bubble_sort<int>(&arr_int, [](int a, int b) {return a > b;});
for (int i = 0; i < 13; i++) {
EXPECT_EQ(arr_int[i], arr_int1[i]);
}
}

TEST(task1, test2) {
double arr_double[] = {1.1, 3.4, 5, 7, 2, 7, 6.6, 4, 6.1, 10};
double arr_int1[] = {1.1, 2, 3.4, 4, 5, 6.1, 6.6, 7, 7, 10};
bubble_sort<double>(&arr_double, [](double a, double b) {return a > b;});
for (int i = 0; i < 10; i++) {
EXPECT_EQ(arr_double[i], arr_int1[i]);
}
}

TEST(task1, test3) {
std::string arr_string[] = {"aa", "bbbb", "ccc", "ddddddd", "e", "ff"};
std::string arr_string2[] = {"e", "aa", "ff", "ccc", "bbbb", "ddddddd"};
bubble_sort<std::string>(&arr_string,
        [](const std::string& a, const std::string& b) {
return a.length() > b.length();
});
for (int i = 0; i < 6; i++) {
EXPECT_EQ(arr_string[i], arr_string2[i]);
}
}

