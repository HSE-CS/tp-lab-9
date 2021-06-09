//  Copyright 2021 GHA created by Klykov Anton

#include <iostream>
#include <cctype>
#include "task1.h"

int main() {
  std::vector<std::string> string;
  string.emplace_back("abcd");
  string.emplace_back("abce");
  string.emplace_back("ABCD");
  string.emplace_back("aBCdEFG");
  auto lexicon_compare = [](const std::string& a,
      const std::string& b) -> bool{
    if(a > b) {
      return true;
    } else {
      return false;
    }
  };
  auto size_comapre = [](const std::string& a,
      const std::string& b) -> bool{
    if(a.size() > b.size()) {
      return true;
    } else {
      return false;
    }
  };
  auto register_compare = [](const std::string& a,
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
  };
  auto amount_upper_compare = [](const std::string& a,
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
  };
  auto amount_lower_compare = [](const std::string& a,
      const std::string& b) -> bool{
    int amount_a = 0;
    int amount_b = 0;
    for (size_t i = 0; i < a.size(); i++) {
      if (islower(a[i])) {
        amount_a++;
      }
    }
    for (size_t i = 0; i < b.size(); i++) {
      if (islower(b[i])) {
        amount_b++;
      }
    }
    return (amount_a > amount_b);
  };
  BubbleSort(string, lexicon_compare);
  for (auto & i : string) {
    std::cout << i << std::endl;
  }
  std::cout << "=============================" << std::endl;
  BubbleSort(string, size_comapre);
  for (auto & i : string) {
    std::cout << i << std::endl;
  }
  std::cout << "=============================" << std::endl;
  BubbleSort(string, register_compare);
  for (auto & i : string) {
    std::cout << i << std::endl;
  }
  std::cout << "=============================" << std::endl;
  BubbleSort(string, amount_upper_compare);
  for (auto & i : string) {
    std::cout << i << std::endl;
  }
  std::cout << "=============================" << std::endl;
  BubbleSort(string, amount_lower_compare);
  for (auto & i : string) {
    std::cout << i << std::endl;
  }
  return 0;
}
