// Copyright 2021 Egor Buzanov

#include "../include/task2.h"

int main() {
  std::vector<std::string> array = {
      "1hc", "luZDb", "bm4oQB", "s0ppSh5raW", "PDnMB0wTxYEnsjB",
      "cn",  "BgPaf", "b3Z"};
  std::thread *t1 = new std::thread(
      threadBubbleSort, &array,
      [](std::string str1, std::string str2) { return (str1 > str2); });
  threadPrint(array);
  t1->join();
  return 0;
}
