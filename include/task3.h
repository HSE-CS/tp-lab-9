
#ifndef TP_LAB_9_TASK3_H
#define TP_LAB_9_TASK3_H

#include <vector>
#include <queue>
#include <mutex>

typedef std::vector <std::string> CustomerType;
typedef std::queue <CustomerType> BoxOffType;

class Shop {
public:
    Shop()=default;
    explicit Shop(unsigned int maxCustomers);
    void Shopping();
    void Shopping(unsigned int);

private:
    std::vector <BoxOffType *> boxOffices;
    std::mutex busy;
    unsigned int maxCustomers = 5;
    void AddNewCustomer();
    int GetIndex();

    void OpenBoxOffice(const CustomerType&);
    void CloseBoxOffice(BoxOffType*);
    void DoWork(unsigned int);

    void PrintBoxOffices();
    void PrintBoxOffices(unsigned int);

    static std::chrono::milliseconds GetDelay();
    static CustomerType GetCustomer();

};



#endif //TP_LAB_9_TASK3_H
