// Copyright 2021 MalininDmitry

#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include "task2.cpp"
#include <mutex>
#include <thread>
#include <queue>


int main() {

    std::vector<int> arr = {1, 5, 2 ,4 ,6 ,7, -4 };
    std::function<bool(int, int)> comp =[](int a, int b){return a>b;};

    std::mutex mtx;
    sorttask2(arr, comp, std::ref(mtx));

    return 0;
}
