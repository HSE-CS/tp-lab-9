// Copyright 12.06.21 DenisKabanov

#include <ctime>
#include "task3.h"
int main() {
  srand(time(nullptr));
  Supermarket* supermarket = new Supermarket();
  supermarket->SupermarketRun();
  return 0;
}
