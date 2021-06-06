// Copyright 2021 MalininDmitry

#include "task1.h"

template<typename T>
void sorttask(std::vector<T> &arr, const std::function<bool(T, T)>& comp) {
    for (int i = 0; i < arr.size()-1; i++) {
        for (int j = 0; j < arr.size() - i-1; j++) {
            if (comp(arr[j] , arr[j+1])) {
                T a = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = a;
            }
        }
    }
}
