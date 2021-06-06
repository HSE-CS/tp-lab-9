// Copyright 2021 FOM
#ifndef INCLUDE_TASK1_H_
#define INCLUDE_TASK1_H_

#include <algorithm>
#include <functional>
#include <vector>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <ostream>
#include <string>


template <typename A, typename Te = typename std::iterator_traits<A>::value_type>
void BubbleSort(A start_,
    A finish_, std::function<bool(const Te &, const Te &)> comp_) {
  for (int i = finish_ - start_ - 1; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      A first_ = start_ + j;
      A first_next_ = start_ + j + 1;
      if (comp_(*first_, *first_next_)) {
        std::iter_swap(first_, first_next_);
      }
    }
  }
}

#endif  //  INCLUDE_TASK1_H_
