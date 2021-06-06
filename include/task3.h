// Copyright 2021 Schenikova

#ifndef INCLUDE_TASK3_H_
#define INCLUDE_TASK3_H_

#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <mutex>
#include <thread>
#include <random>
#include <chrono>

class Consumer {
 public:
    std::vector<int> shops;
    explicit Consumer(std::vector<int> _shops) { shops = _shops; }
    void addProduct() { this->shops.push_back(std::rand()); }
    Consumer();
    ~Consumer();
};

class Shop {
 private:
    std::vector<std::thread*> myThreads;
    std::vector<std::queue<Consumer*>*> consumerQueues;
    int maxProducts;
    int maxPrice;
    int maxConsumers;
    int queueLen;
    std::mutex mut;
 public:
    Shop(int _maxProducts, int _maxPrice, int _maxConsumers, int _queueLen) :
    maxProducts(_maxProducts), maxPrice(_maxPrice),
    maxConsumers(_maxConsumers), queueLen(_queueLen) {}
    void consumerRun(Consumer* currentConsumer, Shop* curShop);
    void queueRun(std::queue <Consumer*> currentConsumers);
    void shopRun();
    int getMaxProducts() { return maxProducts; }
    int getMaxPrice() { return maxPrice; }
    int getMaxConsumers() { return maxConsumers; }
    int getQueueLen() { return queueLen; }
};

#endif  //  INCLUDE_TASK3_H_

