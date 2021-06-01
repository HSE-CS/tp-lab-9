//  Copyright 2021 Nikita Naumov
#include "../include/task1.h"

const int n = 5;

void fillVector(std::vector<std::string>* vector) {
    for (size_t i = 0; i < n; ++i) {
        int len = std::rand()%10 + 1;
        std::string tmp;
        for (size_t j = 0; j < len; ++j) {
            tmp += static_cast<char>(std::rand()%96+32);
        }
        (*vector).push_back(tmp);
    }
}

void printVector(std::vector<std::string> vector) {
    for (auto obj: vector) {
        std::cout << obj << std::endl;
    }
}

int main() {
    srand(time(NULL));
    std::vector<std::string> strVector;
    fillVector(&strVector);
    std::vector<std::string> strVector1(strVector),
                            strVector2(strVector),
                            strVector3(strVector),
                            strVector4(strVector),
                            strVector5(strVector);

    std::cout << std::endl;
    auto comp1 = [](std::string str1, std::string str2)->bool{ 
        return (str1.length() > str2.length() ? true : false);
    };
    auto comp2 = [](std::string str1, std::string str2)->bool{
        return (str1.length() < str2.length() ? true : false);
    };
    auto comp3 = [](std::string str1, std::string str2)->bool{
        return (str1 != str2 ? true : false);
    };
    auto comp4 = [](std::string str1, std::string str2)->bool{
        return (str1 > str2 ? true : false);
    };
    auto comp5 = [](std::string str1, std::string str2)->bool{
        return (str1 < str2 ?  true : false);
    };
    std::cout << std::endl << std::endl;
    stringBubbleSort(strVector1, comp1);
    stringBubbleSort(strVector2, comp2);
    stringBubbleSort(strVector3, comp3);
    stringBubbleSort(strVector4, comp4);
    stringBubbleSort(strVector5, comp5);
    std::cout << "Source vector" << std::endl;
    printVector(strVector);
    std::cout << std::endl << "vect1" << std::endl;
    printVector(strVector1);
    std::cout << std::endl << "vect2" << std::endl;;
    printVector(strVector2);
    std::cout << std::endl << "vect3" << std::endl;;
    printVector(strVector3);
    std::cout << std::endl << "vect4" << std::endl;
    printVector(strVector4);
    std::cout << std::endl << "vect5" << std::endl;
    printVector(strVector5);
    std::cout << std::endl;
    return 0;
}
