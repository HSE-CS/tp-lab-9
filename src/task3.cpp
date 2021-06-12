//  Copyright 2021 by Kartseva Masha
#include "task3.h"

Customer::Customer() {
    int size_prod = rand() % 10 + 5;
    for (int i = 0; i < size_prod; i++) {
        products.push_back(rand() % 20 + 20);
    }
}

std::vector<int> Customer::getProds() {
    return products;
}

void Checkout::addCust(Customer* cust) {
    customers.push(cust);
    size++;
}

int Checkout::getsize() {
    return size;
}

void Checkout::serveCust() {
    int num = 1;
    int cnt;
    while (!customers.empty()) {
        cnt = 0;
        Customer* cust = customers.front();
        for (auto prod : cust->getProds()) {
            cnt += prod;
            std::this_thread::sleep_for(std::chrono::milliseconds(prod * 25));
            }
        mtx.lock();
        std::cout << "Checkout #" << std::this_thread::get_id() << ", customer #" << num++ << " spent " << cnt << std::endl;
        mtx.unlock();
        delete customers.front();
        customers.pop();
    }
}

Shop::Shop() {
    checks.push_back(new Checkout);
    for (size_t i = 0; i < count_cust; i++) {
        Customer* cust = new Customer;
        if (checks.back()->getsize() < que_len) {
            checks.back()->addCust(cust);
        } else {
            threads.push_back(new std::thread(&Checkout::serveCust, *(checks.back())));
            checks.push_back(new Checkout);
            checks.back()->addCust(cust);
        }
    }
    threads.push_back(new std::thread(&Checkout::serveCust, *(checks.back())));
    for (auto t : threads) t->join();
}

Shop::~Shop() {
    for (auto t : threads) delete t;
    for (auto ch : checks) delete ch;
}
