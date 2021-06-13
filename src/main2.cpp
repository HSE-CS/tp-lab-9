// Copyright 11.06.21 DenisKabanov

#include "task2.h"

int main() {
    std::vector<std::string> vec =
        {"1234567",  "123456",   "12345", "1234", "123", "12", "1"};
    bubble(vec, [](std::string str1, std::string str2) {
        return str2.length() > str1.length();
    });
}
