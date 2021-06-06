//Copyright 2021 Kris


#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <mutex>
#include "task1.cpp"

void print_mas(std::vector<std::string> v) {
        for (std::string a : v) {
            std::cout << "\"" << a << "\"" << ", ";
        }
    }

std::vector<std::string> bubblesort(const std::vector<std::string>& vec,
    std::function<bool(std::string, std::string)> comparator) {
    std::vector<std::string> v(vec);
    for (unsigned int i = 0; i < v.size() - 1; ++i) {
        for (unsigned int j = 0; j < v.size() - i - 1; ++j) {
            if (comparator(v[j], v[j + 1])) {
                std::string temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
    return v;
}

int main() {
    std::function<bool(std::string, std::string)> comp_1 = [](std::string a, std::string b) {return a > b; };

    std::function<bool(std::string, std::string)> comp_2 = [](std::string a, std::string b) {
        int count_a = 0;
        int count_b = 0;
        for (int i = 0; i < a.size(); ++i) if (a[i] >= 'A' && a[i] <= 'Z') count_a++;
        for (int i = 0; i < b.size(); ++i) if (b[i] >= 'A' && b[i] <= 'Z') count_b++;
        if (count_a < count_b) return true;
        else return false;
    };

    std::function<bool(std::string, std::string)> comp_3 = [](std::string a, std::string b) {
        int count_a = 0;
        int count_b = 0;
        for (int i = 0; i < a.size(); ++i) if (a[i] == 'a' || a[i] == 'A') count_a++;
        for (int i = 0; i < b.size(); ++i) if (b[i] == 'a' || b[i] == 'A') count_b++;
        if (count_a < count_b) return true;
        else return false;
    };

    std::function<bool(std::string, std::string)> comp_4 = [](std::string a, std::string b) {
        if (a.back() > b.back()) return true;
        else return false;
    };

    std::function<bool(std::string, std::string)> comp_5 = [](std::string a, std::string b) {
        if (a.size() > b.size()) return true;
        else return false;
    };

    std::vector<std::string> v = {"kris", "peper", "salt", 
        "lion", "qwerty", "ytrewq"};
    v = bubblesort(v, comp_1);
    print_mas(v);
    v = bubblesort(v, comp_2);
    print_mas(v);
    v = bubblesort(v, comp_3);
    print_mas(v);
    v = bubblesort(v, comp_4);
    print_mas(v);
    v = bubblesort(v, comp_5);
    print_mas(v);
}
