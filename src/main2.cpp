// Copyright 2021 DBarinov

#include "task2.h"

int main() {
	std::vector<std::string> v_string = { "helllo", "world", "this", "is", "demo" };
	bubbleSortt2(v_string, [](std::string& _str1, std::string& _str2) {
		return _str1.length() > _str2.length(); });
}
