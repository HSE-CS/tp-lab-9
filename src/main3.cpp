// Copyright 2021 Kuznetsov Mikhail

#include "task3.h"
#include <ctime>

int main() {
  srand(time(nullptr));
  Supermarket* supermarket = new Supermarket(15, 40, 10, 5);
  supermarket->run();
  return 0;
}

