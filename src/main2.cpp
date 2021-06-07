// Copyright 2021 FOM

#include "task2.h"

int main() {
    std::vector<std::string> test_ = { "monday", "sunday",
                                    "saturday", "friday" ,
        "wednesday" , "thursday", "tuesday" };
    BubbleSortParrallel(test_, [](const std::string& first_,
        const std::string& second_) {
        return first_.length() > second_.length(); });
}
