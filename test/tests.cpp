// Copyright 2021 NikDemoShow
#include <gtest/gtest.h>
#include "task1.h"
#include "task2.h"
#include "task3.h"
TEST(lab9, test1) {
  std::vector<std::string> Sobj{ "UPAA", "Bcd&1%^qA", "uAAaa   a", "ub/+", "!;;'", "o" };
  Bsort(Sobj, [](std::string a, std::string b) {return a < b; });
  std::vector<std::string> expect =
  { "!;; '", "Bcd&1%^qA", "UPAA", "o", "uAAaa   a", "ub/+" };
  EXPECT_EQ(expect, Sobj);
}

TEST(lab9, test2) {
  std::vector<std::string> Sobj{ "UPAA", "Bcd&1%^qA", "uAAaa   a", "ub/+", "!;;'", "o" };
  Bsort(Sobj, [](std::string a, std::string b) {return a.size() < b.size(); });
  std::vector<std::string> expect =
  { "o", "UPAA !;; '", "ub/+", "uAAaa   a", "Bcd&1%^qA" };
  EXPECT_EQ(expect, Sobj);
}

TEST(lab9, test3) {
  std::vector<std::string> Sobj{ "UPAA", "Bcd&1%^qA", "uAAaa   a", "ub/+", "!;;'", "o" };
  Bsort(Sobj, [](std::string a, std::string b) {
    int ca{ 0 }, cb{ 0 };
    for_each(a.begin(), a.end(), [&ca](char ob) {ca += ob >= 'A' && ob <= 'Z'; });
    for_each(b.begin(), b.end(), [&cb](char ob) {cb += ob >= 'A' && ob <= 'Z'; });
    return ca < cb;
    });
  std::vector<std::string> expect =
  { "o", "!;; '", "ub/+", "uAAaa   a", "Bcd&1%^qA", "UPAA" };
  EXPECT_EQ(expect, Sobj);
}

TEST(lab9, test4) {
  std::vector<std::string> Sobj{ "UPAA", "Bcd&1%^qA", "uAAaa   a", "ub/+", "!;;'", "o" };
  Bsort(Sobj, [](std::string a, std::string b) {
    int ca{ 0 }, cb{ 0 };
    for_each(a.begin(), a.end(), [&ca](char ob) {ca += ob >= 'a' && ob <= 'z'; });
    for_each(b.begin(), b.end(), [&cb](char ob) {cb += ob >= 'a' && ob <= 'z'; });
    return ca < cb;
    });
  std::vector<std::string> expect =
  { "!;; '", "UPAA", "o", "ub/+", "Bcd&1%^qA", "uAAaa   a" };
  EXPECT_EQ(expect, Sobj);
}

TEST(lab9, test5) {
  std::vector<std::string> Sobj{ "UPAA", "Bcd&1%^qA", "uAAaa   a", "ub/+", "!;;'", "o" };
  Bsort(Sobj, [](std::string a, std::string b) {int ca{ 0 }, cb{ 0 };
  for_each(a.begin(), a.end(), [&ca](char ob) {ca += ob < 'A' || ob > 'Z' && ob < 'a' || ob > 'z'; });
  for_each(b.begin(), b.end(), [&cb](char ob) {cb += ob < 'A' || ob > 'Z' && ob < 'a' || ob > 'z'; });
  return ca < cb;
    });
  std::vector<std::string> expect =
  { "UPAA", "o", "ub/+", "uAAaa   a", "Bcd&1%^qA", "!;;'"};
  EXPECT_EQ(expect, Sobj);
}
