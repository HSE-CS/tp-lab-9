// Copyright 2021 VA
#include "task1.h"
#include <algorithm>

int main() {
    std::vector<std::string> arr = 
    { "gggg", "aaaa", "lllll", "bbbbbb", "pppppppp", "dddddd" };
    std::function<bool(std::string, std::string)>  comp = 
        [](std::string a, std::string b) { return a > b; };
    Sort(arr, comp);
    printArr1(arr);
    comp = [](std::string a, std::string b) 
    { return a.length() > b.length(); };
    Sort(arr, comp);
    printArr1(arr);
    comp = [](std::string a, std::string b) 
    { return a[1] > b[1]; };
    Sort(arr, comp);
    printArr1(arr);
    comp = [](std::string a, std::string b) 
    { return a < b; };
    Sort(arr, comp);
    printArr1(arr);
    comp = [](std::string a, std::string b) 
    { return a[a.length() - 1] > b[b.length() - 1]; };
    Sort(arr, comp);
    printArr1(arr);
}
