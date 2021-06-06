// Copyright 2021 DBarinov
#include "task1.h"


int main() {
	std::vector<std::string> v_string = { "helllo", "world", "this", "is", "demo" };
	bubbleSort(v_string, [](std::string& _str1, std::string& _str2) {
		return _str1.length() > _str2.length(); });

	bubbleSort(v_string, [](std::string& _str1, std::string& _str2) {
		return _str1.length() < _str2.length(); });

	bubbleSort(v_string, [](std::string& _str1, std::string& _str2) {
		return _str1 < _str2; });

	bubbleSort(v_string, [](std::string& _str1, std::string& _str2) {
		return _str1 > _str2; });

	bubbleSort(v_string, [](std::string& _str1, std::string& _str2) {
		return _str1[_str1.size() - 1] < _str2[_str2.size() - 1]; });

	bubbleSort(v_string, [](std::string& _str1, std::string& _str2) {
		return _str1[0] < _str2[0]; });

	for (auto x : v_string) {
		std::cout << x << ' ';
	}
	std::cout << '\n';
}
