#include "task3.h"
#include <iostream>
#include <vector>
#include <mutex>
#include <thread>
#include <atomic>
#include <chrono>

int number = 1;

std::thread* Shop::addRegister(Client* client) {
    Register* newReg = new Register();
    newReg->addClient(client);
    newReg->setNumber(number);
    ++number;
    registers.push_back(newReg);
    std::thread* th = new std::thread([newReg]() {
        newReg->doServe();
        });
    return th;
}

void Shop::closeRegister() {

}

void Shop::run(std::vector<Client*> clients) {
    //std::cout << clients[8]->getProduct() << std::endl;
    std::vector<std::thread*> threads;
    std::vector<std::atomic<bool>> threadscheck;
    for (Client* a : clients) {
        if (registers.empty()) {
            threads.push_back(addRegister(a));
        } else {
            bool findRegister = false;
            for (Register* b : registers) {
                if (!b->isFull()) {
                    b->addClient(a);
                    findRegister = true;
                    break;
                }
            }
            if (!findRegister) {
                threads.push_back(addRegister(a));
            }

        }
        std::this_thread::sleep_for(std::chrono::milliseconds(std::rand() % 1000));
    }
    for (Register* a : registers) {
        a->setDone();
    }
    for (std::thread* th : threads) {
        th->join();
    }
}