// Copyright 2021 DBarinov
#ifndef INCLUDE_TASK1_H_
#define INCLUDE_TASK1_H_

#include <iostream>
#include <string>
#include <vector>
#include <utility>

template<class T>
void bubbleSort(std::vector<std::string>& _strarr, T _cmpr) {
	std::size_t n = _strarr.size();
	for (std::size_t i = 0; i < n; i++) {
		for (std::size_t j = 0; j < n - 1; j++) {
			if (_cmpr(_strarr[j + 1], _strarr[j])) {
				std::swap(_strarr[j], _strarr[j + 1]);
			}
		}
	}
}
#endif  //  INCLUDE_TASK1_H_