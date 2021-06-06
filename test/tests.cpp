// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>

#include <algorithm>
#include <mutex>
#include <thread>

#include "task1.h"
#include "task2.h"
#include "task3.h"

TEST(lab9, test1) {
  std::vector<std::string> Strings = {
      "Blackjack", "girls", "Futurama", "yes",     "I",  "am",
      "Bender",    "I",     "mix",      "alcohol", "my", "body",
      "is",        "like",  "a",        "blender"};

  std::function<bool(std::string, std::string)> comp1 =
      [](std::string x, std::string y) { return x[0] < y[0]; };

  Strings = bubbleSort(Strings, comp1);

  std::vector<std::string> expect = {
      "yes", "mix",     "my", "like", "is", "girls",    "body",      "blender",
      "am",  "alcohol", "a",  "I",    "I",  "Futurama", "Blackjack", "Bender"};
  EXPECT_EQ(expect, Strings);
}

TEST(lab9, test2) {
  std::function<bool(std::string, std::string)> comp2 =
      [](std::string x, std::string y) { return x.back() < y.back(); };
  Strings = bubbleSort(Strings, comp2);
  std::vector<std::string> expect = {"my", "body",     "mix",       "yes",
                                     "is", "girls",    "blender",   "Bender",
                                     "am", "alcohol",  "Blackjack", "like",
                                     "a",  "Futurama", "I",         "I"};
  EXPECT_EQ(expect, Strings);
}

TEST(lab9, test3) {
  std::function<bool(std::string, std::string)> comp3 = [](std::string x,
                                                           std::string y) {
    return x[x.size() / 3] < y[y.size() / 3];
  };
  Strings = bubbleSort(Strings, comp3);
  std::vector<std::string> expect = {
      "Futurama", "body", "Bender", "my",      "mix",     "is",
      "girls",    "like", "yes",    "blender", "alcohol", "Blackjack",
      "am",       "a",    "I",      "I"};
  EXPECT_EQ(expect, Strings);
}

TEST(lab9, test4) {
  std::function<bool(std::string, std::string)> comp4 =
      [](std::string x, std::string y) { return x.size() < y.size(); };
  Strings = bubbleSort(Strings, comp4);
  std::vector<std::string> expect = {
      "Blackjack", "Futurama", "blender", "alcohol", "Bender", "girls",
      "body",      "like",     "mix",     "yes",     "my",     "is",
      "am",        "a",        "I",       "I"};
  EXPECT_EQ(expect, Strings);
}

TEST(lab9, test5) {
  std::function<bool(std::string, std::string)> comp5 =
      [](std::string x, std::string y) { return x < y; };
  Strings = bubbleSort(Strings, comp5);
  std::vector<std::string> expect = {
      "yes", "my",      "mix", "like", "is", "girls",    "body",      "blender",
      "am",  "alcohol", "a",   "I",    "I",  "Futurama", "Blackjack", "Bender"};
  EXPECT_EQ(expect, Strings);
}
