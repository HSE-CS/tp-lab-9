// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "task1.h"
#include "task2.h"
#include "task3.h"

TEST(Test, test1) {
  std::vector<std::string> arr1 = { "3", "2", "1", "15" };
  bubble(arr1, [](std::string& s1, std::string& s2) {
    return std::stoi(s1) < std::stoi(s2);
  });
  EXPECT_EQ({ "1", "2", "3", "15"}, arr1);
}

TEST(Test, test2) {
  std::vector<std::string> arr2 = { "3", "2", "1", "15" };
  bubble(arr2, [](std::string& s3, std::string& s4) {
    return std::stoi(s4) < std::stoi(s3);
  });
  EXPECT_EQ({ "15", "3", "2", "1" }, arr2);
}

TEST(Test, test3) {
  std::vector<std::string> arr3 = { "3", "2", "1", "15" };
  bubble(arr3, [](std::string& s5, std::string& s6) {
    return s5.size() < s6.size();
  });
  EXPECT_EQ({ "3", "2", "1", "15" }, arr3);
}

TEST(Test, test4) {
  std::vector<std::string> arr4 =  { "3", "2", "1", "15" };
  bubble(arr4, [](std::string& s7, std::string& s8) {
    return s8.size() < s7.size();
  });
  EXPECT_EQ({ "15", "3", "2", "1" }, arr4);
}

TEST(Test, test5) {
  std::vector<std::string> arr5 = { "3", "2", "1", "15" };
  bubble(arr5, [](std::string& s9, std::string& s10) { return s9[0] < s10[0]; });
  EXPECT_EQ({ "15", "1", "2", "3" }, arr5);
}
