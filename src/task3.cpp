// Copyright 2021 kisozinov

#include "task3.h"
#include <zconf.h>

void service(std::deque<std::vector<int>*>* line_customers, int active) {
    while (!line_customers->empty()) {
        std::ostringstream s;
        s << "{ ";
        for (int i : *line_customers->front()) {
            s << i << " ";
        }
        usleep((std::rand() % 54000) * line_customers->front()->size());
        std::cout << "Line [ " << active << " ] served customer " << s.str() << "}"
            << '\n';
        line_customers->pop_front();
    }
}
