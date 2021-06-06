// Copyright 2021 LongaBonga

#include "task3.h"
#include <zconf.h>
#include <iostream>
#include <sstream>

void service(std::deque<std::vector<int>*>* line_customers, int active) {
    while (!line_customers->empty()) {
        std::ostringstream s;
        s << "{ ";
        for (int i : *line_customers->front()) {
            s << i << " ";
        }
        usleep((rand() % 54000) * line_customers->front()->size());
        std::cout << "Line [ " << active << " ] served customer " <<
                  s.str() << "}" <<  '\n';
        line_customers->pop_front();
    }
}
