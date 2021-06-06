// Copyright 2021 alexgiving

#ifndef INCLUDE_TASK3_H_
#define INCLUDE_TASK3_H_

 #include <iostream>
 #include <utility>
 #include <vector>
 #include <queue>
 #include <mutex>
 #include <thread>

 class Buyer {
  public:
     std::vector<int> list;
     explicit Buyer(std::vector<int> _list) { this->list = std::move(_list); }
 };

 class Supermarket {
  private:
     std::vector<std::queue<Buyer*>*> buyers;
     std::vector<std::thread*> threads;
     int MN = 10;

  public:
     Supermarket() = default;;
     static Buyer* createBuyer();
     void BuyerRun(Buyer*, int);
     void BuyerPrint(int, int);
     void QueueRun(std::queue <Buyer*>*);
     void SupermarketRun();
 };

#endif  // INCLUDE_TASK3_H_
