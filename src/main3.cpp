// Copyright 2021 DBarinov

#include "task3.h"
#include <ctime>

int main() {
	srand(time(nullptr));
	Shop* shop = new Shop();
	shop->ShopRun();
	return 0;
}
