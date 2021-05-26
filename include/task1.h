#pragma once
#include <algorithm>
#include <functional>
#include <vector>

template <typename It,
          typename T = typename std::iterator_traits<It>::value_type>
void bubble_sort(It it_begin, It it_end,
                 std::function<bool(const T &, const T &)> gt_comp) {
  for (size_t i = it_end - it_begin - 1; i > 0; --i) {
    for (size_t j = 0; j < i; ++j) {
      It a = it_begin + j;
      It b = it_begin + j + 1;
      if (gt_comp(*a, *b)) {
        std::iter_swap(a, b);
      }
    }
  }
}
