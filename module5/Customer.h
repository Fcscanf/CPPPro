//
// Created by fcsca on 2019-03-03/0003.
//

#ifndef PRO1_CUSTOMER_H
#define PRO1_CUSTOMER_H

#include <cstdlib>

using namespace std;

class Customer {
private:
    long arrive;
    int processtime;
public:
    Customer(){ arrive = processtime = 0; }

    void set(long when);

    long when()const { return arrive; }

    int ptime()const { return processtime; }

};

void Customer::set(long when) {
    processtime = rand() % 3 + 1;
    arrive = when;
}


#endif //PRO1_CUSTOMER_H
