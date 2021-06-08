// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "task1.h"
#include "task2.h"
#include "task3.h"


TEST(lab9, Task1_test1) {
    std::vector<std::string> words = { "hello", "world", "i", "am", "the", "star",
    "lord", "gaze", "upon", "my", "might" };
    words = BubbleSort(words, [](std::string x, std::string y)
    {return x.size() > y.size(); });
    std::vector<std::string> expect =
    { "the", "i", "star", "gaze", "world", "am", "my", "might", "lord", "hello", "upon" };
    EXPECT_EQ(expect, words);
}


TEST(lab9, Task1_test2) {
    std::vector<std::string> words = { "hello", "world", "i", "am", "the", "star",
    "lord", "gaze", "upon", "my", "might" };
    words = BubbleSort(words, [](std::string x, std::string y)
    {return x[0] > y[0]; });
    std::vector<std::string> expect = { "star", "am", "the", "world", "upon",
    "might", "i", "gaze", "hello", "lord", "my" };
    EXPECT_EQ(expect, words);
}
