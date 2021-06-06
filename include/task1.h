// Copyright 2021 MalininDmitry

#ifndef INCLUDE_FIRSTTASK_H_
#define INCLUDE_FIRSTTASK_H_
#include <iostream>
#include <functional>
#include <vector>
#include <string>


template<typename T>
void sorttask(std::vector<T> &arr, const std::function<bool(T, T)>& comp);

#endif  // INCLUDE_FIRSTTASK_H_
