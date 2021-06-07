// Copyright Slavokeru 2021
#ifndef INCLUDE_TASK3_H_
#define INCLUDE_TASK3_H_
#include<iostream>
#include<queue>
#include<mutex>
#include<set>
#include<vector>
#include<thread>
#include<utility>

struct buyer {
  std::vector<int> purch;
  int pay{ std::rand() % 10 };
};

class SM {
  static const unsigned int limit{ 10 }, cnt{ 25 };
  std::mutex m;
  std::set<std::pair<std::thread*, std::queue<buyer*>*>> Kass;
  std::set<buyer*> buyers;
 public:
  void run();
  friend void cbrun(std::queue<buyer*>*);
};
void cbrun(std::queue<buyer*>*);
#endif  // INCLUDE_TASK3_H_
