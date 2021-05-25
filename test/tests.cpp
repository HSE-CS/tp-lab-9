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
