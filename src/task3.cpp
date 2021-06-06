// Copyright 2021 SoDa

#include "task3.h"
#include <iostream>


Client* Shop::new_client() {
    int num_purchases = std::rand() % 20 + 1;
    std::vector<int> purchases;
    for (int i = 0; i < num_purchases; i++) {
        purchases.push_back(std::rand() % 500 + 1);
    }
    return new Client(purchases);
}

void Shop::shop_life() {
    for (int i = 0; i < this->clients_num; i++) {
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
                (*client_it)->push(new_client());
                is_queue = true;
                break;
            }
        }
        if (!is_queue) {
            std::queue <Client*>* queue_ptr = new std::queue <Client*>;
            queue_ptr->push(this->new_client());
            this->Clients.push_back(queue_ptr);
            threads.push_back(new std::thread(&Shop::work_with_queue,
                this, queue_ptr));
        }
    }
}

void Shop::work_with_queue(std::queue <Client*>* clients_) {
    while (!clients_->empty()) {
        Client* client = clients_->front();
        work_with_client(client);
        clients_->pop();
    }
    delete clients_;
}

void Shop::work_with_client(Client* client) {
    for (auto i = 0; i < client->purchases_size(); i++) {
        int time = std::rand() % 5000 + 1;
        std::this_thread::sleep_for(std::chrono::milliseconds(time));
        std::unique_lock<std::mutex> t_lock(mtx);
        std::cout << "Cash register  " << std::this_thread::get_id()
            << " serves the customer " <<
            client->get_client_id() << ", who bought " << i + 1
            << " by price: " << client->get_purchas(i) << '\n';
        t_lock.unlock();
    }
}

void Shop::work() {
    shop_life();
    for (auto que : threads) {
        que->join();
    }
}
