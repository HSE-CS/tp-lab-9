// Copyright 2021 DBarinov

#include "task2.h"
#include <thread>

void BubbleSort(std::vector<std::string>& _strarr,
	bool _cmpr(const std::string _str1, const std::string _str2)) {
	std::vector<std::string> v_string(_strarr);
	std::mutex a;
	std::size_t n = v_string.size();
	for (std::size_t i = 0; i < n - 1; i++) {
		std::thread thread([&v_string, &_cmpr, &a, &i, &n]() {
			for (std::size_t j = 0; j < n - i - 1; j++) {
				if (_cmpr(v_string[j + 1], v_string[j])) {
					a.lock();
					std::string temp = v_string[j];
					v_string[j] = v_string[j + 1];
					v_string[j + 1] = temp;
					a.unlock();
				}
			}
			});
		thread.join();
		for (auto x : v_string) {
			std::cout << x << ' ';
		}
		std::cout << '\n';
	}
}
