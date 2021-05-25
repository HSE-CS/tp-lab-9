// Copyright 2021 valvarl

#include <deque>
#include <zconf.h>
#include <iostream>
#include <sstream>
#include "task3.h"

void service(std::deque<std::vector<int>*>* line_customers, int active) {
    while (!line_customers->empty()) {
        std::ostringstream s;
        s << "[ ";
        for (int i : *line_customers->front()) {
            s << i << " ";
        }
        usleep( (simple_rand() % 50000) * line_customers->front()->size() );
        std::cout << "Line [ " << active << " ] served customer with items " <<
                  s.str() << "]" <<  std::endl;
        line_customers->pop_front();
    }
}
