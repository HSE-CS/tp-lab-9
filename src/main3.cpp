// Copyright 2021 S
#include <unistd.h>
#include <thread>
#include "task3.h"

int main() {
    auto* line = new std::deque<std::vector<int>*>{};
    int buyers = std::rand() % 100 + 100;
    int a = 0;

    while (buyers) {
        auto* p = new
                std::vector<int>(static_cast<int>(std::rand() % 10 + 1), 0);
        for (int i = 0; i < p->size(); i++) {
            p->at(i) = std::rand() % 10;
        }
        line->push_back(p);
        if (line->size() == 5) {
            std::thread th(service, line, a++);
            th.detach();
            line = new std::deque<std::vector<int>*>{};
        }
        usleep(std::rand() % 55000);
        --buyers;
    }
}
