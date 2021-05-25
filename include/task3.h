// Copyright 2021 valvarl

#ifndef INCLUDE_TASK3_H_
#define INCLUDE_TASK3_H_

#include <random>

std::minstd_rand simple_rand;

void service(std::deque<std::vector<int>*>* line_customers, int active);

#endif  // INCLUDE_TASK3_H_
