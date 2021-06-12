//  Copyright 2021 by Kartseva Masha
#include "task1.h"
void BubbleSort(std::vector<std::string>& arr, bool comparator(const std::string& a, const std::string& b))
{
    std::vector<std::string>::iterator pos;
    for (size_t i = 0; i < arr.size() - 1; i++) {
        for (size_t j = 0; j < arr.size() - 1 - i; j++) {
            if (comparator(arr[j], arr[j + 1])) swap(arr[j], arr[j + 1]);
        }
    }
    for (pos = arr.begin(); pos != arr.end(); pos++) {
        std::cout << *pos << " ";
    }
    std::cout << std::endl;
}
