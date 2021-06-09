// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "include/task1.h"
#include "include/task2.h"
#include "include/task3.h"

TEST(Task1, test_lexicon) {
  std::vector<std::string> string;
  string.emplace_back("abcd");
  string.emplace_back("abce");
  string.emplace_back("ABCD");
  string.emplace_back("aBCdEFG");
  std::vector<std::string> expected;
  expected.emplace_back("ABCD");
  expected.emplace_back("aBCdEFG");
  expected.emplace_back("abcd");
  expected.emplace_back("abce");
  BubbleSort(string, [](const std::string& a,
      const std::string& b) -> bool{
    if(a > b) {
      return true;
    } else {
      return false;
    }
  });
  for (size_t i = 0; i < expected.size(); ++i) {
    EXPECT_EQ(string, expected);
  }
}
TEST(Task1, test_size) {
  std::vector<std::string> string;
  string.emplace_back("ABCD");
  string.emplace_back("aBCdEFG");
  string.emplace_back("abcd");
  string.emplace_back("abce");
  std::vector<std::string> expected;
  expected.emplace_back("ABCD");
  expected.emplace_back("abcd");
  expected.emplace_back("abce");
  expected.emplace_back("aBCdEFG");
  BubbleSort(string, [](const std::string& a,
      const std::string& b) -> bool{
    if(a.size() > b.size()) {
      return true;
    } else {
      return false;
    }
  });
  for (size_t i = 0; i < expected.size(); ++i) {
    EXPECT_EQ(string, expected);
  }
}
TEST(Task1, test_register) {
  std::vector<std::string> string;
  string.emplace_back("ABCD");
  string.emplace_back("abcd");
  string.emplace_back("abce");
  string.emplace_back("aBCdEFG");
  std::vector<std::string> expected;
  expected.emplace_back("ABCD");
  expected.emplace_back("abcd");
  expected.emplace_back("abce");
  expected.emplace_back("aBCdEFG");
  BubbleSort(string, [](const std::string& a,
      const std::string& b) -> bool{
  for (size_t i = 0; i < std::min(a.size(),
                                  b.size()); ++i) {
    if (isupper(a[i]) && isupper(b[i])) {
      if(a[i] >= b[i]) {
        return true;
      } else {
        return false;
      }
    } else {
      continue;
    }
  }
  return false;
  });
  for (size_t i = 0; i < expected.size(); ++i) {
    EXPECT_EQ(string, expected);
  }
}
TEST(Task1, test_upper) {
  std::vector<std::string> string;
  string.emplace_back("ABCD");
  string.emplace_back("abcd");
  string.emplace_back("abce");
  string.emplace_back("aBCdEFG");
  std::vector<std::string> expected;
  expected.emplace_back("abcd");
  expected.emplace_back("abce");
  expected.emplace_back("ABCD");
  expected.emplace_back("aBCdEFG");
  BubbleSort(string, [](const std::string& a,
      const std::string& b) -> bool{
    int amount_a = 0;
    int amount_b = 0;
    for (size_t i = 0; i < a.size(); i++) {
      if (isupper(a[i])) {
        amount_a++;
      }
    }
    for (size_t i = 0; i < b.size(); i++) {
      if (isupper(b[i])) {
        amount_b++;
      }
    }
    return amount_a > amount_b;
  });
  for (size_t i = 0; i < expected.size(); ++i) {
    EXPECT_EQ(string, expected);
  }
}
