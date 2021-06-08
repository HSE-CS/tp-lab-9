// Copyright 2021 FOM

#include "task3.h"

Buyer* Seller::buyer_make() {
    std::vector<int> vector_;
    int count_purchases = std::rand() % 9 + 1;
    vector_.reserve(count_purchases);
    for (int i = 0; i < count_purchases; i++)
        vector_.push_back(std::rand() % 10 + 1);
    return new Buyer(vector_);
}

void Seller::buyer_start(Buyer* buyer, int buyer_id) {
    std::mutex a;
    for (int product_id = 0; product_id < buyer->list.size(); product_id++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::unique_lock<std::mutex> unqLock(a);
        unqLock.unlock();
    }
}

void Seller::queue_start(std::queue <Buyer*>* buyers_queue) {
    int buyer_id = 1;
    while (!buyers_queue->empty()) {
        auto new_buyer = buyers_queue->front();
        buyer_start(new_buyer, buyer_id++);
    }
    delete buyers_queue;
}

void Seller::start() {
    for (int i = 0; i < MN; i++) {
        bool FQ = false;
        for (auto buyer = buyers.begin(); buyer != buyers.end(); buyer++) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            if ((*buyer)->size() < 10 && (*buyer) != nullptr) {
                (*buyer)->push(buyer_make());
                FQ = true;
                break;
            } else
                if ((*buyer) == nullptr)
                    buyers.erase(buyer);
        }
        if (!FQ) {
            auto* _queue_ptr = new std::queue <Buyer*>;
            _queue_ptr->push(this->buyer_make());
            buyers.push_back(_queue_ptr);
            threads.push_back(new std::thread(&Seller::queue_start,
                this, _queue_ptr));
        }
    }
    for (auto thread : threads) thread->join();
}
