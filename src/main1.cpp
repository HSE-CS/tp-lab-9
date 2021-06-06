// Copyright 2021 MalininDmitry

#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include "task1.h"
#include <mutex>
#include <thread>
#include <queue>

int main() {
    std::vector<int> arr = {1, 5, 2 ,4 ,6 ,7, -4 };
    std::function<bool(int, int)> comp =[]
    (int a, int b){return a>b;};
    sorttask(arr, comp);
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::vector<double> arr2 = {1.4, 5.2,
        2.3 ,4.1 ,6.4 ,7.4, -4.4 };
    std::function<bool(double, double)> comp2 =[]
    (double a, double b){return a>b;};
    sorttask(arr2, comp2);
    for (int i = 0; i < arr2.size(); i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    std::vector<std::string> arr3 = {"aaa",
        "ccc", "ddd"};
    std::function<bool(std::string, std::string)>
    comp3 =[](std::string a, std::string b){return a>b;};
    sorttask(arr3, comp3);
    for (int i = 0; i < arr3.size(); i++) {
        std::cout << arr3[i] << " ";
    }
    std::cout << std::endl;

    std::vector<std::string> arr4 = {"a", "ccc",
        "dd", "asdasd"};
    std::function<bool(std::string, std::string)>
    comp4 =[](std::string a, std::string b){return
        a.length()>b.length();};
    sorttask(arr4, comp4);
    for (int i = 0; i < arr4.size(); i++) {
        std::cout << arr4[i] << " ";
    }
    std::cout << std::endl;

    std::vector<std::string> arr5 = {"a", "ccc",
        "dd", "asdasd"};
    std::function<bool(std::string, std::string)>
    comp5 =[](std::string a, std::string b){return
        a.length()%3 >b.length()%3;};
    sorttask(arr5, comp5);
    for (int i = 0; i < arr5.size(); i++) {
        std::cout << arr5[i] << " ";
    }
    std::cout << std::endl;
    
    std::vector<std::string> arr6 = {"a", "ccc",
        "dd", "asdasd"};
    std::function<bool(std::string, std::string)>
    comp6 =[](std::string a, std::string b){return
        a[0] < b[0];};
    sorttask(arr6, comp6);
    for (int i = 0; i < arr6.size(); i++) {
        std::cout << arr6[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
