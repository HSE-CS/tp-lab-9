// Copyright 2021 kisozinov

#include <unistd.h>
#include <iostream>
#include <thread>
#include "task3.h"

int main() {
    int customers{ static_cast<int>(std::rand() % 100 + 100) };
    int active = 0;
    auto* line_customers = new std::deque<std::vector<int>*>{};

    while (customers) {
        auto* perches =
            new std::vector<int>(static_cast<int>(std::rand() % 10 + 1), 0);
        for (int i{ 0 }; i < perches->size(); i++) {
            perches->at(i) = std::rand() % 10;
        }
        line_customers->push_back(perches);
        if (line_customers->size() == 5) {
            std::thread th(service, line_customers, active++);
            th.detach();
            line_customers = new std::deque<std::vector<int>*>{};
        }
        usleep(std::rand() % 55000);
        customers--;
    }
}
