//Copyright 2021 Kris


#include "task3.h"

std::thread* Shop::addSeller(Client* client) {
    int i = 1;
    Seller* newReg = new Seller();
    newReg->addClient(client);
    newReg->setNumber(i);
    ++i;
    sellers.push_back(newReg);
    std::thread* th = new std::thread([newReg]() {
        newReg->doServe();
        });
    return th;
}

void Shop::run(std::vector<Client*> clients) {
    std::vector<std::thread*> threads;
    std::vector<std::atomic<bool>> threadscheck;
    for (Client* a : clients) {
        if (sellers.empty()) {
            threads.push_back(addSeller(a));
        }
        else {
            bool findSeller = false;
            for (Seller* b : sellers) {
                if (!b->isFull()) {
                    b->addClient(a);
                    findSeller = true;
                    break;
                }
            }
            if (!findSeller) {
                threads.push_back(addSeller(a));
            }
        }
        std::this_thread::sleep_for(
            std::chrono::milliseconds(std::rand() % 1000));
    }
    for (Seller* a : sellers) {
        a->setDone();
    }
    for (std::thread* th : threads) {
        th->join();
    }
}