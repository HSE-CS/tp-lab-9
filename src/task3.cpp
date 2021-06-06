// Copyright 2021 VA
#include "task3.h"

void Shop::run(Customer* cust) {
    for (int i = 0; i < cust->getGoodsSize(); i++) {
        std::this_thread::sleep_for(
            std::chrono::milliseconds(cust->getGood(i)));
    }
}

void Shop::runService(std::queue<Customer*>* q) {
    while (!(*q).empty()) {
        auto cust = q->front();
        run(cust);
    }
}

void Shop::run() {
    for (int i = 0; i < num; i++) {
        bool isCreateQueu = true;
        for (auto i = queue.begin(); i != queue.end(); i++) {
            if ((*i) == nullptr) {
                queue.erase(i);
            } else if ((*i)->size() < 5) {
                (*i)->push(new Customer(createGoods()));
                isCreateQueu = false;
                break;
            }
        }
        if (isCreateQueu) {
            auto q = new std::queue <Customer*>;
            q->push(new Customer(createGoods()));
            queue.push_back(q);
            threads.push_back(new std::thread(&Shop::runService, this, q));
        }
    }
}

std::vector<int> Shop::createGoods() {
    std::vector<int> products;
    for (int i = 0; i < 8; i++) {
        products.push_back(std::rand() % 20);
    }
    return products;
}

int Customer::getGoodsSize() {
    return goods.size();
}

int Customer::getGood(int position) {
    return goods[position];
}
