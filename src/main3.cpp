// Copyright 2021 valvarl

#include <thread>
#include <vector>
#include <deque>
#include "task3.cpp"


int main() {
    simple_rand.seed(
    std::chrono::system_clock::now().time_since_epoch().count());
    //simple_rand.seed(44);

    int customers{ static_cast<int>(simple_rand() % 100 + 100) }, active{ 0 };
    auto* line_customers = new std::deque<std::vector<int>*>{};

    while (customers) {
        auto *perches = new std::vector<int>(static_cast<int>(simple_rand() % 10 + 1), 0);
        for (int i { 0 }; i < perches->size(); i++) {
            perches->at(i) = simple_rand() % 10;
        }
        line_customers->push_back(perches);
        if (line_customers->size() == 5) {
            std::thread th(service, line_customers, active++);
            th.detach();
            line_customers = new std::deque<std::vector<int>*>{};
        }
        usleep( simple_rand() % 50000 );
        customers--;
    }
}
