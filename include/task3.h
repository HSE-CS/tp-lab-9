//  Copyright 2021 by Kartseva Masha
#pragma once
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <algoriithm>
#include <queue>
#include <random>
#include <chrono>
#define TASK3_H
#ifdef TASK3_H
extern const int count_cust;
extern const int que_len;
extern std::mutex mtx;

class Customer {
 private:
    std::vector<int> products;
 public:
    Customer();
    std::vector<int> getProds();
};

class Checkout {
 private:
    int size = 0;
    std::queue<Customer*> customers;
 public:
    Checkout() {}
    void addCust(Customer* cust);
    int getsize();
    void serveCust();
};


class Shop {
 private:
    std::vector<std::thread*> threads;
    std::vector<Checkout*> checks;
 public:
    Shop();
    ~Shop();
};
#endif  //  TASK3_H
