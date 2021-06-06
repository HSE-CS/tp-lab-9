// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "task1.h"
#include "task2.h"
#include "task3.h"


TEST(lab9, Task1_test1) {
  std::vector<std::string> words = {"please", "let", "me", "die", "i", "am",
    "tired", "of", "living", "this", "life"};
  words = BubbleSort(words, [](std::string x, std::string y)
    {return x.size() > y.size(); });
  std::vector<std::string> expect =
  {"i", "me", "am", "of", "let", "die", "this", "life", "tired", "please", "living"};
  EXPECT_EQ(expect, words);
}

TEST(lab9, Task1_test2) {
  std::vector<std::string> words = {"please", "let", "me", "die", "i", "am",
    "tired", "of", "living", "this", "life"};
  words = BubbleSort(words, [](std::string x, std::string y)
    {return x[0] > y[0]; });
  std::vector<std::string> expect =
  {"am", "die", "i", "let", "life", "living", "me", "of", "please", "this", "tired"};
  EXPECT_EQ(expect, words)
}

