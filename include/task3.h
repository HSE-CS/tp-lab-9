// Copyright 2021 Bogomazov
#ifndef INCLUDE_TASK_THIRD_H_
#define INCLUDE_TASK_THIRD_H_

#include <list>
#include <mutex>
#include <queue>
#include <thread>
#include <random>
#include <string>
#include <vector>
#include <iterator>
#include <iostream>
#include <functional>
#include <condition_variable>


static int num_client = 0;

class Client {
 private:
    int clientId;
    std::vector<int> purchases;
 public:
    explicit Client(std::vector<int> purchases_) : purchases(purchases_),
        clientId(++num_client) {}
    int purchasesSize() { return this->purchases.size(); }
    int getPurchas(int id) { if (id >= 0 && id <= purchasesSize()) {
        return purchases[id];
        } throw;
    return 0; }
    int getClientId() { return this->clientId; }
};


class Shop {
 private:
    std::vector<std::thread*> threads;
    std::vector<std::queue<Client*>*> Clients;
    size_t clients_num;
    std::mutex mtx;
 public:
    explicit Shop(int clients_num_) : clients_num(clients_num_) {}
    Client* newClient();
    void shopLife();
    void work();
    void workWithClient(Client*);
    void workWithQueue(std::queue <Client*>*);
};

#endif  //  INCLUDE_TASK_THIRD_H_
