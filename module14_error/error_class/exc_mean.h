//
// Created by fcsca on 2019-03-08/0008.
//

#ifndef PRO1_EXC_MEAN_H
#define PRO1_EXC_MEAN_H


#include <iostream>

using namespace std;

class bad_hmean {
private:
    double v1;
    double v2;
public:
    bad_hmean(double a = 0, double b = 0) : v1(a), v2(b){}
    void mesg();
};

inline void bad_hmean::mesg() {
    cout << "hmean(" << v1 << ", " << v2 << "): " << "invalid argumets: a = -b\n";
}

class bad_gmean{
public:
    double v1;
    double v2;
    bad_gmean(double a = 0, double b = 0) : v1(a), v2(b){}
    const char *mesg();
};

inline const char * bad_gmean::mesg() {
    return "gmean() arguments should be >= 0\n";
}


#endif //PRO1_EXC_MEAN_H
