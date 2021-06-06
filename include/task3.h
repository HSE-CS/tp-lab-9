// Copyright NikDemoShow 2021
#ifndef INCLUDE_TASK3_H_
#define INCLUDE_TASK3_H_
#include<iostream>
#include<set>
#include<vector>
#include<thread>
#include<queue>
#include<mutex>

struct buyer {
  std::vector<int> purch;
  int timeToPay{ std::rand() % 15 };
};

class Shop {
  static const unsigned int lim{ 5 }, buyerscnt{ 15 };
  std::mutex mu;
  std::set<std::pair<std::thread*, std::queue<buyer*>*>> cashBoxes;
  std::set<buyer*> buyers;
 public:
  void work();
  friend void cbwork(std::queue<buyer*>*);
};
void cbwork(std::queue<buyer*>*);
#endif  // INCLUDE_TASK3_H_
