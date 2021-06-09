// Copyright 2021 Vadukk

#include "task3.h"
#include <ctime>
int main() {
	srand(time(nullptr));
	Supermarket* supermarket = new Supermarket();
	supermarket->SupermarketRun();
	return 0;
}