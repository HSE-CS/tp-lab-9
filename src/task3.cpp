// Copyright 2021 Bogomazov

#include "../include/task3.h"
#include <iostream>


Client* Shop::newClient() {
    int num_purchases = std::rand() % 20 + 1;
    std::vector<int> purchases;
    for (int i = 0; i < num_purchases; i++) {
        purchases.push_back(std::rand() % 500 + 1);
    }
    return new Client(purchases);
}

void Shop::shopLife() {
    for (int i = 0; i < static_cast<int>(this->clients_num); i++) {
        bool is_queue = false;
        for (auto client_it = this->Clients.begin();
            client_it != this->Clients.end(); client_it++) {
            int time = std::rand() % 1500;
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
            if ((*client_it) == nullptr) {
                Clients.erase(client_it);
                continue;
            }
            if ((*client_it)->size() < 5) {
                (*client_it)->push(newClient());
                is_queue = true;
                break;
            }
        }
        if (!is_queue) {
            std::queue <Client*>* queue_ptr = new std::queue <Client*>;
            queue_ptr->push(this->newClient());
            this->Clients.push_back(queue_ptr);
            threads.push_back(new std::thread(&Shop::workWithQueue,
                this, queue_ptr));
        }
    }
}

void Shop::workWithQueue(std::queue <Client*>* clients_) {
    while (!clients_->empty()) {
        Client* client = clients_->front();
        workWithClient(client);
        clients_->pop();
    }
    delete clients_;
}

void Shop::workWithClient(Client* client) {
    for (auto i = 0; i < client->purchasesSize(); i++) {
        int time = std::rand() % 5000 + 1;
        std::this_thread::sleep_for(std::chrono::milliseconds(time));
        std::unique_lock<std::mutex> t_lock(mtx);
        std::cout << "Cash register  " << std::this_thread::get_id()
            << " serves the customer " <<
            client->getClientId() << ", who bought " << i + 1
            << " by price: " << client->getPurchas(i) << '\n';
        t_lock.unlock();
    }
}

void Shop::work() {
    shopLife();
    for (auto que : threads) {
        que->join();
    }
}
