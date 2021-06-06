// Copyright 2021 GN
#ifndef INCLUDE_TASK3_H_
#define INCLUDE_TASK3_H_
#include <iostream>
#include <vector>
#include <queue>
#include <mutex>
#include <thread>

class Buyer {
 public:
    std::vector<int> list;
    explicit Buyer(std::vector<int> list_) {
        list = list_;
    }
};

class Supermarket {
 private:
    std::vector<std::queue<Buyer*>*> buyers;
    std::vector<std::thread*> threads;
    int maxNumber = 100;

 public:
    Supermarket() {};
    Buyer* createBuyer();
    void BuyerRun(Buyer* buyer_, int id_);
    void BuyerPrint(int id_, int i);
    void QueueRun(std::queue <Buyer*>* buyers_);
    void SupermarketRun();
};

#endif  //  INCLUDE_TASK3_H_
