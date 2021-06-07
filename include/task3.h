// Copyright 2021 FOM
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
    explicit Buyer(std::vector<int> _list) { list = std::move(_list); }
};
class Seller {
 private:
    std::vector<std::queue<Buyer*>*> buyers;
    std::vector<std::thread*> threads;
    int MN = 10;
 public:
    static Buyer* buyer_make();
    void buyer_start(Buyer*, int);
    void queue_start(std::queue <Buyer*>*);
    void start();
};

#endif  //  INCLUDE_TASK3_H_
