// Copyright 2021 MalininDmitry

#ifndef INCLUDE_SECONDTASK_H_
#define INCLUDE_SECONDTASK_H_
#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <mutex>
#include <thread>

template<typename T>
void sorttask2(std::vector<T> &arr, const std::function<bool(T, T)>& comp, std::mutex &mtx);
template<typename T>
void printarr(std::vector<T> &arr, std::mutex &mtx);
#endif  // INCLUDE_SECONDTASK_H_
