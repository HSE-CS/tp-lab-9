// Copyright 2021 GN
#include "task3.h"

void Supermarket::BuyerRun(Buyer* buyer_, int id_) {
    int time = std::rand() % 1500;
    std::mutex a;
    for (int i = 0; i < buyer_->list.size(); i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(time));
        std::unique_lock<std::mutex> unqLock(a);
        BuyerPrint(id_, i);
        unqLock.unlock();
    }
}
void Supermarket::BuyerPrint(int id_, int i) {
    std::cout << std::this_thread::get_id()
        << "-" << id_ << "-" << i + 1 << std::endl;
}
void Supermarket::QueueRun(std::queue <Buyer*>* buyers_) {
    int id = 1;
    while (!buyers_->empty()) {
        auto buyer = buyers_->front();
        BuyerRun(buyer, id);
        id++;
    }
    delete buyers_;
}
Buyer* Supermarket::createBuyer() {
    int PurchasesNumber = std::rand() % 10 + 1;
    std::vector<int> list_;
    for (int i = 0; i < PurchasesNumber; i++) {
        list_.push_back(std::rand() % 300 + 1);
    }
    return new Buyer(list_);
}
void Supermarket::SupermarketRun() {
    int time = std::rand() % 1500;
    for (int i = 0; i < maxNumber; i++) {
        bool FQ = false;
        for (auto buyer = buyers.begin(); buyer != buyers.end(); buyer++) {
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
            if ((*buyer)->size() < 10 && (*buyer) != nullptr) {
                (*buyer)->push(createBuyer());
                FQ = true;
                break;
            } else if ((*buyer) == nullptr) {
                buyers.erase(buyer);
            }
        }
        if (FQ == false) {
            std::queue <Buyer*>* queue_ptr = new std::queue <Buyer*>;
            queue_ptr->push(this->createBuyer());
            buyers.push_back(queue_ptr);
            threads.push_back(new std::thread(&Supermarket::QueueRun, this, queue_ptr));
        }
    }
    for (auto thread : threads) {
        thread->join();
    }
}
