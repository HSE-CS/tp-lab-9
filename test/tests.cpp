// Copyright 2021 Slavokeru
#include <gtest/gtest.h>
#include "task1.h"
TEST(lab9, test1) {
  std::vector<std::string> Vec
  { "first", "second", "three", "four", "million", "monday" };
  BS(&Vec, [](std::string a, std::string b) {return a < b; });
  std::vector<std::string> expect =
  { "first", "second", "three", "four", "million", "monday" };
  EXPECT_EQ(expect, Vec);
}

TEST(lab9, test2) {
  std::vector<std::string> Vec
  { "first", "second", "three", "four", "million", "monday" };
  BS(&Vec, [](std::string a, std::string b) {  return a[0] < b[0]; });
  std::vector<std::string> expect =
  { "first", "second", "three", "four", "million", "monday" };
  EXPECT_EQ(expect, Vec);
}

TEST(lab9, test3) {
  std::vector<std::string> Vec
  { "first", "second", "three", "four", "million", "monday" };
  BS(&Vec, [](std::string a, std::string b) {
    int ca{ 0 }, cb{ 0 };
    for_each(a.begin(), a.end(), [&ca](char ob)
      {ca += ob >= 'a' && ob <= 'z'; });
    for_each(b.begin(), b.end(), [&cb](char ob)
      {cb += ob >= 'a' && ob <= 'z'; });
    return ca < cb;
    });
  std::vector<std::string> expect =
  { "first", "second", "three", "four", "million", "monday" };
  EXPECT_EQ(expect, Vec);
}

TEST(lab9, test4) {
  std::vector<std::string> Vec
  { "first", "second", "three", "four", "million", "monday" };
  BS(&Vec, [](std::string a, std::string b) {
    int A{ 0 }, B{ 0 };
    for_each(a.begin(), a.end(), [&A](char ob)
      {A += ob >= 'a' && ob <= 'z'; });
    for_each(b.begin(), b.end(), [&B](char ob)
      {B += ob >= 'a' && ob <= 'z'; });
    return A < B;
    });
  std::vector<std::string> expect =
  { "first", "second", "three", "four", "million", "monday" };
  EXPECT_EQ(expect, Vec);
}

TEST(lab9, test5) {
  std::vector<std::string> Vec
  { "first", "second", "three", "four", "million", "monday" };
  BS(&Vec, [](std::string a, std::string b) {return a[1] < b[1]; });
  std::vector<std::string> expect =
  { "first", "second", "three", "four", "million", "monday" };
  EXPECT_EQ(expect, Vec);
}
