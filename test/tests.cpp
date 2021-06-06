// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "../include/task1.h"
#include "../include/task2.h"
#include "../include/task3.h"

TEST(task_1, test_1) {
  std::vector<std::string> v = {"Hello   ", "WORLD",
                             "long string with a lot of spaces", "TP laaab 9"};
  bubble_sort(
      v, [](std::string s1, std::string s2) { return s1.size() > s2.size(); });

  std::vector<std::string> expect = {"WORLD", "Hello   ", "TP laaab 9",
                                     "long string with a lot of spaces"};
  EXPECT_EQ(expect, v);
}

TEST(task_1, test_2) {
  std::vector<std::string> v = {
      "Hello   ", "WORLD", "long string with a lot of spaces", "TP laaab 9"};
  bubble_sort(v, [](std::string s1, std::string s2) {
    int count = 0;
    for (auto i : s1) {
      if (i == ' ') ++count;
    }
    for (auto i : s2) {
      if (i == ' ') --count;
    }
    return count > 0;
  });

  std::vector<std::string> expect = {"WORLD", "TP laaab 9", "Hello   ",
                                     "long string with a lot of spaces"};
  EXPECT_EQ(expect, v);
}

TEST(task_1, test_3) {
  std::vector<std::string> v = {
      "Hello   ", "WORLD", "long string with a lot of spaces", "TP laaab 9"};
  bubble_sort(v, [](std::string s1, std::string s2) {
    int count = 0;
    for (auto i : s1) {
      if (i == 'a' || i == 'e' || i == 'y' || i == 'u' || i == 'i' ||
          i == 'o' || i == 'A' || i == 'E' || i == 'Y' || i == 'U' ||
          i == 'I' || i == 'O')
        ++count;
    }
    for (auto i : s2) {
      if (i == 'a' || i == 'e' || i == 'y' || i == 'u' || i == 'i' ||
          i == 'o' || i == 'A' || i == 'E' || i == 'Y' || i == 'U' ||
          i == 'I' || i == 'O')
        --count;
    }
    return count > 0;
  });

  std::vector<std::string> expect = {"WORLD", "Hello   ", "TP laaab 9",
                                     "long string with a lot of spaces"};
  EXPECT_EQ(expect, v);
}

TEST(task_1, test_4) {
  std::vector<std::string> v = {
      "Hello   ", "WORLD", "long string with a lot of spaces", "TP laaab 9"};
  bubble_sort(v, [](std::string s1, std::string s2) {
    int count = 0;
    for (auto i : s1) {
      if (i >= 'A' && i <= 'Z') ++count;
    }
    for (auto i : s2) {
      if (i >= 'A' && i <= 'Z') --count;
    }
    return count > 0;
  });

  std::vector<std::string> expect = {"long string with a lot of spaces",
                                     "Hello   ", "TP laaab 9", "WORLD"};
  EXPECT_EQ(expect, v);
}

TEST(task_1, test_5) {
  std::vector<std::string> v = {
      "Hello   ", "WORLD", "long string with a lot of spaces", "TP laaab 9"};
  bubble_sort(v, [](std::string s1, std::string s2) {
    size_t size = (s1.size() > s2.size() ? s1.size() : s2.size());
    for (size_t i = 0; i < size; ++i) {
      if (i == s1.size()) return false;
      if (i == s2.size()) return true;
      if (s1[i] > s2[i]) return true;
    }
    return false;
  });

  std::vector<std::string> expect = {
      "TP laaab 9", "long string with a lot of spaces", "WORLD", "Hello   "};
  EXPECT_EQ(expect, v);
}
