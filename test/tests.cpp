// Copyright 2021 Kuznetsov Mikhail
#include <gtest/gtest.h>
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include <algorithm>
#include <thread>
#include <mutex>
#include <condition_variable>

extern bool isPrinted;
extern bool isSorted;
extern bool isStepped;
extern std::mutex myMutex;
extern std::condition_variable condVar;

TEST(lab9, Task1_test1) {
  std::vector<std::string> vectStr = {"summer", "is", "coming",
  "my", "dear", "friends"};
  bubbleSort(vectStr, [](std::string &x, std::string &y) { return x < y; });
  std::vector<std::string> expect =
  {"coming", "dear", "friends", "is", "my", "summer"};
  EXPECT_EQ(expect, vectStr);
}

TEST(lab9, Task1_test2) {
  std::vector<std::string> vectStr = {"Summer", "is", "coming",
  "my", "Dear", "Friends"};
  bubbleSort(vectStr, [](std::string &x, std::string &y) { return x < y; });
  std::vector<std::string> expect =
  {"Dear", "Friends", "Summer", "coming", "is", "my"};
  EXPECT_EQ(expect, vectStr);
}

TEST(lab9, Task1_test3) {
  std::vector<std::string> vectStr = {"summer", "is", "coming",
  "my", "dear", "friends"};
  bubbleSort(vectStr, [](std::string &x, std::string &y) {
             return x.back() < y.back(); });
  std::vector<std::string> expect =
  {"coming", "summer", "dear", "is", "friends", "my"};
  EXPECT_EQ(expect, vectStr);
}

TEST(lab9, Task1_test4) {
  std::vector<std::string> vectStr = {"summer", "is", "coming",
  "my", "dear", "friends"};
  bubbleSort(vectStr, [](std::string &x, std::string &y) {
             return x[x.size() / 2] < y[y.size() / 2]; });
  std::vector<std::string> expect =
  {"dear", "friends", "coming", "summer", "is", "my"};
  EXPECT_EQ(expect, vectStr);
}

TEST(lab9, Task1_test5) {
  std::vector<std::string> vectStr = {"summer", "is", "coming",
  "my", "dear", "friends"};
  bubbleSort(vectStr, [](std::string &x, std::string &y) {
             return x.size() < y.size(); });
  std::vector<std::string> expect =
  {"is", "my", "dear", "summer", "coming", "friends"};
  EXPECT_EQ(expect, vectStr);
}

TEST(lab9, Task1_test6) {
  std::vector<std::string> vectStr = {"summer", "is", "coming",
  "my", "dear", "friends"};
  bubbleSort(vectStr, [](std::string x, std::string y) {
    std::reverse(x.begin(), y.end());
    std::reverse(x.begin(), y.end());
    return x < y;
  });
  std::vector<std::string> expect =
  {"coming", "dear", "friends", "is", "my", "summer"};
  EXPECT_EQ(expect, vectStr);
}

TEST(lab9, Task1_test7) {
  std::vector<std::string> vectStr = {"summer", "is", "coming",
  "my", "dear", "friends"};
  bubbleSort(vectStr, [](std::string x, std::string y) {
    char a = x[0], b = y[0];
    std::remove(x.begin(), x.end(), a);
    std::remove(y.begin(), y.end(), b);
    return x < y;
  });
  std::vector<std::string> expect =
  {"dear", "coming", "friends", "is", "summer", "my"};
  EXPECT_EQ(expect, vectStr);
}
