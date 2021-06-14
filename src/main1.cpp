//  Copyright 2021 by Kartseva Masha
#include "task1.h"

int main() {
    std::vector<std::string> vec = { "summer", "hse", "exams",
    "weekdays", "or", "weekends" };
    std::cout << "sort by decrease : " << std::endl;
    BubbleSort(vec, [](const std::string& a,
    const std::string& b) {return a < b; });
    std::cout << "\nsort by increase : " << std::endl;
    BubbleSort(vec, [](const std::string& a,
    const std::string& b) {return a > b; });
    std::cout << "\nsort by size increase : " << std::endl;
    BubbleSort(vec, [](const std::string& a,
    const std::string& b) {return a.size() > b.size(); });
    std::cout << "\nsort by size decrease : " << std::endl;
    BubbleSort(vec, [](const std::string& a,
    const std::string& b) {return a.size() < b.size(); });
    std::cout << "\nsort by last symbol increase : " << std::endl;
    BubbleSort(vec, [](const std::string& a,
    const std::string& b) {return  *(a.end() - 1) > * (b.end() - 1); });
    return 0;
}
