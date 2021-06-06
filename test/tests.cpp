// Copyright 2021 Egor Buzanov
#include <gtest/gtest.h>

#include "task1.h"

TEST(Sort, test1) {
  std::vector<std::string> array = {
      "1hc", "luZDb", "bm4oQB", "s0ppSh5raW", "PDnMB0wTxYEnsjB",
      "cn",  "BgPaf", "b3Z"};
  bubbleSort(&array, [](std::string str1, std::string str2) {
    return str1.size() > str2.size();
  });
  std::vector<std::string> expect = {
      "cn",    "1hc",    "b3Z",        "luZDb",
      "BgPaf", "bm4oQB", "s0ppSh5raW", "PDnMB0wTxYEnsjB"};
  EXPECT_EQ(expect, array);
}

TEST(Sort, test2) {
  std::vector<std::string> array = {
      "1hc", "luZDb", "bm4oQB", "s0ppSh5raW", "PDnMB0wTxYEnsjB",
      "cn",  "BgPaf", "b3Z"};
  bubbleSort(&array, [](std::string str1, std::string str2) {
    unsigned int num_str1 = std::count(str1.begin(), str1.end(), 'a');
    unsigned int num_str2 = std::count(str2.begin(), str2.end(), 'a');
    return (num_str1 > num_str2);
  });
  std::vector<std::string> expect = {
      "1hc", "luZDb", "bm4oQB",     "PDnMB0wTxYEnsjB",
      "cn",  "b3Z",   "s0ppSh5raW", "BgPaf"};
  EXPECT_EQ(expect, array);
}

TEST(Sort, test3) {
  std::vector<std::string> array = {
      "1hc", "luZDb", "bm4oQB", "s0ppSh5raW", "PDnMB0wTxYEnsjB",
      "cn",  "BgPaf", "b3Z"};
  bubbleSort(&array,
             [](std::string str1, std::string str2) { return (str1 > str2); });
  std::vector<std::string> expect = {"1hc",   "BgPaf",     "PDnMB0wTxYEnsjB",
                                     "b3Z",   "bm4oQB",    "cn",
                                     "luZDb", "s0ppSh5raW"};
  EXPECT_EQ(expect, array);
}

TEST(Sort, test4) {
  std::vector<std::string> array = {
      "1hc", "luZDb", "bm4oQB", "s0ppSh5raW", "PDnMB0wTxYEnsjB",
      "cn",  "BgPaf", "b3Z"};
  bubbleSort(&array, [](std::string str1, std::string str2) {
    return (str1[0] > str2[0]);
  });
  std::vector<std::string> expect = {"1hc",    "BgPaf",     "PDnMB0wTxYEnsjB",
                                     "bm4oQB", "b3Z",       "cn",
                                     "luZDb",  "s0ppSh5raW"};
  EXPECT_EQ(expect, array);
}

TEST(Sort, test5) {
  std::vector<std::string> array = {
      "1hc", "luZDb", "bm4oQB", "s0ppSh5raW", "PDnMB0wTxYEnsjB",
      "cn",  "BgPaf", "b3Z"};
  bubbleSort(&array, [](std::string str1, std::string str2) {
    return (str1[str1.size() - 1] > str2[str2.size() - 1]);
  });
  std::vector<std::string> expect = {
      "bm4oQB", "PDnMB0wTxYEnsjB", "s0ppSh5raW", "b3Z", "luZDb",
      "1hc",    "BgPaf",           "cn"};
  EXPECT_EQ(expect, array);
}
