// Copyright 2021 alexgiving

#include "task3.h"
#include <ctime>

int main() {
  srand(time(nullptr));
  auto* supermarket = new Supermarket();
  supermarket->SupermarketRun();


  return 0;
}
