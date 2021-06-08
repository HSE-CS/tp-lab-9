
#include <thread>
#include <iostream>

#include "task3.h"

using namespace std;

int main(){

    Shop newWorkableShop(10);
    newWorkableShop.Shopping(15);
    newWorkableShop.Shopping();

    return 0;
}
