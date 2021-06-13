// Copyright 2021 S

#include "task3.h"
#include <sstream>
#include <zconf.h>
#include <iostream>

void service(std::deque<std::vector<int>*>* buyers,
             int a) {
    while (!buyers->empty()) {
        std::ostringstream string;
        string << "{ ";
        for (auto i : *buyers->front()) {
            string << i << " ";
        }
        usleep((std::rand() % 54000) * buyers->front()->size());
        std::cout << "Line [ " << a << " ] served customer " <<
            string.str() << "}" << '\n';
        buyers->pop_front();
    }
}
