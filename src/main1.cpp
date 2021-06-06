// Copyright 2021 Egor Buzanov

#include "../include/task1.h"

int main() {
  std::vector<std::string> array = {
      "1hc", "luZDb", "bm4oQB", "s0ppSh5raW", "PDnMB0wTxYEnsjB",
      "cn",  "BgPaf", "b3Z"};
  bubbleSort(&array, [](std::string str1, std::string str2) {
    return str1.size() > str2.size();
  });
  print(array);
  bubbleSort(&array, [](std::string str1, std::string str2) {
    unsigned int num_str1 = std::count(str1.begin(), str1.end(), 'a');
    unsigned int num_str2 = std::count(str2.begin(), str2.end(), 'a');
    return (num_str1 > num_str2);
  });
  print(array);
  bubbleSort(&array,
             [](std::string str1, std::string str2) { return (str1 > str2); });
  print(array);
  bubbleSort(&array, [](std::string str1, std::string str2) {
    return (str1[0] > str2[0]);
  });
  print(array);
  bubbleSort(&array, [](std::string str1, std::string str2) {
    return (str1[str1.size() - 1] > str2[str2.size() - 1]);
  });
  print(array);
  return 0;
}
