// Copyright 2021 Soda
#ifndef INCLUDE_TASK3_H_
#define INCLUDE_TASK3_H_

#include <string>
#include <vector>
#include <iterator>
#include <iostream>
#include <functional>
#include <mutex>
#include <queue>
#include <list>
#include <condition_variable>
#include <thread>
#include <random>


static int num_client = 0;

class Ñlient {
private:
    int client_id;
    std::vector<int> purchases;
public:
    explicit Ñlient(std::vector<int> purchases_) : purchases(purchases_), client_id(++num_client) {};
    int purchases_size() { return this->purchases.size(); }
    int get_purchas(int id) { if (id >= 0 && id <= purchases_size()) { return purchases[id]; } throw; return 0; }
    int get_client_id() { return this->client_id; }
};


class Shop {
private:
    std::vector<std::thread*> threads;
    std::vector<std::queue<Ñlient*>*> Clients;
    size_t clients_num;
    std::mutex mtx;
public:
    Shop(int clients_num_) : clients_num(clients_num_) {};
    Ñlient* new_client();
    void shop_life();
    void work();
    void work_with_client(Ñlient*);
    void work_with_queue(std::queue <Ñlient*>*);

};

#endif  //  INCLUDE_TASK3_H_

