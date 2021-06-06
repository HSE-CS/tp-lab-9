// Copyright 2021 me
#include <iostream>
#include <thread>
#include "../include/task2.h"

std::function<bool(std::string, std::string)> f1 =
    [](std::string s1, std::string s2) { return s1.size() > s2.size(); };


void fun() {
  for (int i = 0; true; ++i) {
    std::cout << i << "\n";
  }
}


int main() {
  std::vector<std::string> v;
  v.push_back("aaaa");
  v.push_back("aaa");
  v.push_back("aa");
  v.push_back("a");

  std::mutex mtx;
  bool work = true;
  std::thread thr1(task2, std::ref(v), std::ref(f1), std::ref(work),
                   std::ref(mtx));
  std::thread thr2(print_vector, std::ref(v), std::ref(work), std::ref(mtx));
  thr1.join();
  thr2.join();
  return 0;
}
