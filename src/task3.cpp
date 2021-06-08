
#include <iostream>
#include <thread>

#include "task3.h"

using namespace std;

Shop::Shop(unsigned int maxCustomers){
    this->maxCustomers = maxCustomers;
}

void Shop::Shopping() {
    this->Shopping(50);
}

void Shop::Shopping(unsigned int customers) {

    for (int i = 0; i < customers; i++){
        cout << "Customer #" << i + 1 << endl;
        this->PrintBoxOffices();
        this->AddNewCustomer();
        this_thread::sleep_for(GetDelay());
    }

    while(!(this->boxOffices.empty()));
}

void Shop::AddNewCustomer() {

    CustomerType customer = GetCustomer();

    if(this->boxOffices.empty()){
        cout << "First box office!!!" << endl;
        this->OpenBoxOffice(customer);
        return;
    }

    int index = this->GetIndex();
    if (index >= 0){
        lock_guard<mutex> lock(this->busy);
        this->boxOffices[index]->push(customer);
        return;
    }
    this->OpenBoxOffice(customer);
}

int Shop::GetIndex() {

    for (int index = 0; index < this->boxOffices.size(); index++){
        if(this->boxOffices[index]->size() < this->maxCustomers){
            return index;
        }
    }
    return -1;

}

void Shop::OpenBoxOffice(const CustomerType & customer) {

    auto *newBoxOffice = new BoxOffType;
    int index = 0;
    newBoxOffice->push(customer);
    {
        lock_guard<mutex> lock(this->busy);
        index = (int) this->boxOffices.size();
        this->boxOffices.push_back(newBoxOffice);
    }
        thread newBoxOfficeThread(&Shop::DoWork, this, index);
        newBoxOfficeThread.detach();
        cout << "New Box Office #" << index << "!" << endl;

}

void Shop::CloseBoxOffice(BoxOffType *boxOffice) {

    for(auto realIndex = 0; realIndex < this->boxOffices.size(); realIndex++){
        if(this->boxOffices[realIndex] == boxOffice){
            this->boxOffices.erase(this->boxOffices.begin() + realIndex);
            delete boxOffice;
            return;
        }
    }

}

void Shop::DoWork(unsigned int index) {

    BoxOffType *boxOffice = this->boxOffices[index];

    while(true){
        CustomerType customer;
        {
            lock_guard<mutex> lock(this->busy);
            if (boxOffice->empty()) {
                cout << "Box office #" << index << " is empty!" << endl;
                this->CloseBoxOffice(boxOffice);
                this->busy.unlock();
                return;
            }
            this->PrintBoxOffices(index);
            customer = boxOffice->front();
            boxOffice->pop();
        }

        while(!(customer.empty())){
            customer.pop_back();
            this_thread::sleep_for(chrono::milliseconds(500));
        }

    }
}


void Shop::PrintBoxOffices() {

    cout << "Box Offices: ";
    for(auto BO:this->boxOffices){
        cout << "\t(" << BO->size() << ")";
    }
    cout << endl;

}

void Shop::PrintBoxOffices(unsigned int index ) {

    cout << "Box Offices: ";
    for(auto BO:this->boxOffices){
        cout << "\t(" << BO->size() << ")";
    }
    cout << "\t#" << index;
    cout << endl;

}

chrono::milliseconds Shop::GetDelay() {

    unsigned int delay = rand() % 1500; // NOLINT(cert-msc50-cpp)
    return (chrono::milliseconds) delay;

}

CustomerType Shop::GetCustomer() {

    CustomerType customer;

    unsigned int goods = rand() % 15; // NOLINT(cert-msc50-cpp)
    customer.reserve(goods);
    while(goods--){
        customer.push_back("Goods");
    }

    return customer;
}