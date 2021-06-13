//  Copyright 2021 by Kartseva Masha
#include "task2.h"
std::mutex mtx;
std::condition_variable cv;
bool finish(false), printed(true), sorted(false);
void BubbleSort(const std::vector<std::string>& arr,
bool comparator(const std::string& a, const std::string& b)) {
    std::vector<std::string>::iterator pos;
    for (size_t i = 0; i < arr.size() - 1; i++) {
        std::unique_lock<std::mutex> ul(mtx);
        cv.wait(ul, []() {return printed; });
        for (size_t j = 0; j < arr.size() - 1 - i; j++) {
            if (comparator(arr[j], arr[j + 1])) {
                swap(arr[j], arr[j + 1]);
            }
        }
        printed = false;
        sorted = true;
        ul.unlock();
        cv.notify_all();
    }
    finish = true;
}
