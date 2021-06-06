// Copyright 2021 VA
#ifndef INCLUDE_TASK3_H_
#define INCLUDE_TASK3_H_
#include <vector>
#include <thread>
#include <queue>
#include <mutex>
#include <thread>
class Customer {
private: 
    std::vector<int> goods;
public:
    explicit Customer(std::vector<int> goods) {
        this->goods = goods;
    }
    int getGoodsSize();
    int getGood(int position);
};

class Shop {
private:
    std::vector<std::thread*> threads;
    std::vector<std::queue<Customer*>*> queue;
    const int num = 50;
public:
    Shop() {};
    void run(Customer* cust);
    void runService(std::queue <Customer*>* q);
    void run();
    std::vector<int> createGoods();
};
#endif  // INCLUDE_TASK3_H_
